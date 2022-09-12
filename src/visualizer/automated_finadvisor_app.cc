#include <visualizer/automated_finadvisor_app.h>
#include "core/momentum-prediction/momentum_training_data_factory.h"
#include <float.h>
#include "cinder/Text.h"
#include <string>
#include <sstream>
#include "core/data_processor.h"
#include "visualizer/technical_chart_visualizer.h"
#include "core/momentum-prediction/momentum_classifier.h"
#include "core/momentum-prediction/momentum_model.h"
#include "core/volatility-prediction/volatility_model.h"
#include "core/volatility-prediction/volatility_classifier.h"

using std::to_string;

namespace finadvisor {

namespace visualizer {

size_t AutomatedFinadvisorApp::GetLineWidth() {
    return kLineWidth_;
}

double AutomatedFinadvisorApp::GetWindowSize() {
    return kWindowSize_;
}

double AutomatedFinadvisorApp::GetMargin() {
    return kMargin_;
}

AutomatedFinadvisorApp::AutomatedFinadvisorApp() {
    ci::app::setWindowSize((int) kWindowSize_, (int) kWindowSize_);
}

void AutomatedFinadvisorApp::DrawNextButton() const {
    ci::gl::color(ci::Color(0, 1, 0));
    ci::gl::drawSolidRect(ci::Rectf(4 * kWindowSize_ / 5, 4 * kWindowSize_ / 5, (4 * kWindowSize_ / 5) + 100,
                                    (4 * kWindowSize_ / 5) + 50));
    ci::gl::drawStringCentered("Next Month", glm::vec2((4 * kWindowSize_ / 5) + 50, (4 * kWindowSize_ / 5) + 25),
                               ci::Color(1, 1, 1));
}

void AutomatedFinadvisorApp::SketchAxes() {
    ci::gl::color(ci::Color(1, 0, 1));
    ci::gl::drawLine(glm::vec2(10.5 * AutomatedFinadvisorApp::GetWindowSize() / 20, 3 * AutomatedFinadvisorApp::GetWindowSize() / 4),
                     glm::vec2(10.5 * AutomatedFinadvisorApp::GetWindowSize() / 20, (3 * AutomatedFinadvisorApp::GetWindowSize() / 4)
                                                                                    - AutomatedFinadvisorApp::GetLineWidth()));
    ci::gl::drawLine(glm::vec2(10.5 * AutomatedFinadvisorApp::GetWindowSize() / 20 + AutomatedFinadvisorApp::GetLineWidth(),
                               3 * AutomatedFinadvisorApp::GetWindowSize() / 4),
                     glm::vec2(10.5 * AutomatedFinadvisorApp::GetWindowSize() / 20, 3 * AutomatedFinadvisorApp::GetWindowSize() / 4));
}

bool operator<(const DailyPrice& first_price, const DailyPrice& second_price) {
    return std::tie(first_price.closing_price, first_price.opening_price, first_price.low_price, first_price.high_price) <
           std::tie(second_price.closing_price, second_price.opening_price, second_price.low_price, second_price.high_price);
}

void AutomatedFinadvisorApp::SketchCandleBody(const vector<DailyPrice>& daily_prices, double max_high_price,
                                                      double min_low_price) {
    float horizontal_position = 10.5 * AutomatedFinadvisorApp::GetWindowSize() / 20;
    double vertical_position = 6 * AutomatedFinadvisorApp::GetWindowSize() / 11;
    float incremental_value = static_cast<float>(AutomatedFinadvisorApp::GetLineWidth()) / daily_prices.size();

    for (const DailyPrice &daily_price : daily_prices) {
        float scaled_high_price = (daily_price.high_price * AutomatedFinadvisorApp::GetLineWidth()) /
                                  ((max_high_price - min_low_price) * 25);
        float scaled_low_price = (daily_price.low_price * AutomatedFinadvisorApp::GetLineWidth()) /
                                 ((max_high_price - min_low_price) * 75);
        float scaled_closing_price = (daily_price.closing_price * AutomatedFinadvisorApp::GetLineWidth()) /
                                     ((max_high_price - min_low_price) * 50);
        float scaled_opening_price = (daily_price.opening_price * AutomatedFinadvisorApp::GetLineWidth()) /
                                     ((max_high_price - min_low_price) * 50);
        prices_by_chart_location_.insert({vertical_position, daily_price});
        // Upper Candlestick wick
        ci::gl::color(ci::Color(1, 1, 1));
        ci::gl::drawLine(glm::vec2(horizontal_position + (incremental_value / 2), vertical_position),
                         glm::vec2(horizontal_position + (incremental_value / 2), vertical_position - scaled_high_price));
        if (daily_price.opening_price > daily_price.closing_price) {
            ci::gl::color(ci::Color(1, 0, 0));
            ci::gl::drawSolidRect(
                    ci::Rectf(horizontal_position, vertical_position, horizontal_position + incremental_value,
                              vertical_position - scaled_closing_price));
            ci::gl::color(ci::Color(1, 1, 1));
            // Lower Candlestick wick
            ci::gl::drawLine(glm::vec2(horizontal_position + (incremental_value / 2), vertical_position),
                             glm::vec2(horizontal_position + (incremental_value / 2), vertical_position + scaled_low_price));
            vertical_position = vertical_position + scaled_closing_price;
        } else if (daily_price.closing_price > daily_price.opening_price) {
            ci::gl::color(ci::Color(0, 1, 0));
            ci::gl::drawSolidRect(
                    ci::Rectf(horizontal_position, vertical_position, horizontal_position + incremental_value,
                              vertical_position - scaled_opening_price));
            ci::gl::color(ci::Color(1, 1, 1));
            // Lower Candlestick wick
            ci::gl::drawLine(glm::vec2(horizontal_position + (incremental_value / 2), vertical_position),
                             glm::vec2(horizontal_position + (incremental_value / 2), vertical_position + scaled_low_price));
            vertical_position = vertical_position - scaled_opening_price;
        } else {
            ci::gl::color(ci::Color(1, 1, 0));
            ci::gl::drawLine(glm::vec2(horizontal_position, vertical_position),
                             glm::vec2(horizontal_position + incremental_value, vertical_position));
        }
        horizontal_position += incremental_value + 1;
    }
}

void AutomatedFinadvisorApp::draw() {
    ci::Color8u background_color(1, 0, 1);
    ci::gl::clear(background_color);

    DrawNextButton();
    vector<std::string> file_paths = {"abengoa.csv"};
    TechnicalChartVisualizer technical_chart_visualizer;
    technical_chart_visualizer.DrawTechnicalChart(file_paths, month_index_);

    SketchAxes();
    finadvisor::VolatilityTrainingDataFactory volatility_factory;
    volatility_factory = volatility_factory.ValidateFiles(file_paths);
    vector<DailyPrice> daily_prices;
    double max_high_price = DBL_MIN;
    double min_low_price = DBL_MAX;
    daily_prices.reserve(kAverageMonthlyTradingDays_);
    for (size_t i = kAverageMonthlyTradingDays_ * month_index_; i < kAverageMonthlyTradingDays_ * (month_index_ + 1); i++) {
        DailyPrice daily_price = volatility_factory.GetDailyPrice(i);
        if (daily_price.high_price > max_high_price) {
            max_high_price = daily_price.high_price;
        }
        if (daily_price.low_price < min_low_price) {
            min_low_price = daily_price.low_price;
        }
        daily_prices.emplace_back(volatility_factory.GetDailyPrice(i));
    }
    SketchCandleBody(daily_prices, max_high_price, min_low_price);

    ci::gl::drawStringCentered(
            "Press Delete to clear the momentum and volatility prediction. Press Enter to make a prediction.",
            glm::vec2(kWindowSize_ / 2, kMargin_ / 2), ci::Color(1, 1, 0));

    ci::gl::drawStringCentered(
            "Momentum Prediction: " + current_momentum_prediction_ + "; " + "Volatility Prediction: " +
            current_volatility_prediction_, glm::vec2(kWindowSize_ / 2, kMargin_ / 6), ci::Color(0, 1, 0));

    ci::gl::drawStringCentered(
            "Momentum Validation Accuracy: " + std::to_string(momentum_validation_accuracy_) + "; " + "Volatility Validation Accuracy: " +
            std::to_string(volatility_validation_accuracy_), glm::vec2(kWindowSize_ / 2, (3 * kWindowSize_ / 4) + 50), ci::Color(1, 1, 0));

    // Price Summary
    DataProcessor processor;
    float vertical_position = 4 * kMargin_ / 5;
    std::vector<std::string> summary_components = processor.Split(price_summary_, "\n");
    for (const std::string& summary_component : summary_components) {
        ci::gl::drawStringCentered(summary_component, glm::vec2(kWindowSize_ / 2, vertical_position), ci::Color(0, 1, 1));
        vertical_position += 15;
    }
}

ostream& operator<<(ostream& output, DailyPrice& price) {
    output << "Price summary" << "\n";
    output << "Opening Price: " << std::to_string(static_cast<double>(price.opening_price)) << "\n";
    output << "Closing Price: " << std::to_string(static_cast<double>(price.closing_price)) << "\n";
    output << "High Price: " << std::to_string(static_cast<double>(price.high_price)) << "\n";
    output << "Low Price: " << std::to_string(static_cast<double>(price.low_price));
    return output;
}

void AutomatedFinadvisorApp::mouseDown(cinder::app::MouseEvent event) {
    // Click Next Month Button
    if (event.getPos().x >= (4 * kWindowSize_ / 5) && event.getPos().y >= (4 * kWindowSize_ / 5) &&
        event.getPos().x <= ((4 * kWindowSize_ / 5) + 50) && event.getPos().y <= ((4 * kWindowSize_ / 5) + 25)) {
        month_index_++;
    }

    // Click Chart Candle or Technical Chart Trend Line
    for (std::pair<const float, DailyPrice> price_by_location : prices_by_chart_location_) {
        if (event.getPos().y >= price_by_location.first && event.getPos().y <= price_by_location.first +
            (static_cast<float>(AutomatedFinadvisorApp::kLineWidth_) / kAverageMonthlyTradingDays_))  {
            DailyPrice price = price_by_location.second;
            std::stringstream stream;
            stream << price;
            price_summary_ = stream.str();
        }
    }
}

void AutomatedFinadvisorApp::keyDown(ci::app::KeyEvent event) {
    switch (event.getCode()) {
        case ci::app::KeyEvent::KEY_DELETE:
            current_momentum_prediction_ = "";
            current_volatility_prediction_ = "";
            break;
        case ci::app::KeyEvent::KEY_RETURN:
            vector<std::string> file_paths = {"abengoa.csv"};
            try {
                finadvisor::MomentumTrainingDataFactory momentum_factory;
                momentum_factory = momentum_factory.ValidateFiles(file_paths);
                current_momentum_prediction_ = kMomentumCategories_[static_cast<int>(
                        momentum_factory.GetMomentum(month_index_).category)] + " " + kMomentumDirections_[
                                static_cast<int>(momentum_factory.GetMomentum(month_index_).direction)];
                finadvisor::MomentumClassifier momentum_classifier;
                finadvisor::MomentumModel momentum_model;
                momentum_classifier.CalculateValidationAccuracy(momentum_model, 0);

                finadvisor::VolatilityTrainingDataFactory volatility_factory;
                volatility_factory = volatility_factory.ValidateFiles(file_paths);
                current_volatility_prediction_ = kVolatilityMeasures_[static_cast<int>(
                        volatility_factory.GetVolatility(month_index_).measure)] + " " + kVolatilityCategories_[
                                static_cast<int>(volatility_factory.GetVolatility(month_index_).category)];
                finadvisor::VolatilityClassifier volatility_classifier;
                finadvisor::VolatilityModel volatility_model;
                volatility_classifier.CalculateValidationAccuracy(volatility_model, 0);
            } catch (const std::exception& exception) {
                month_index_--;
            }
            break;
    }
}

}  // namespace visualizer

}  // namespace finadvisor
