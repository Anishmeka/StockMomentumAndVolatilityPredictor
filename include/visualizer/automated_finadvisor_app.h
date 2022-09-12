#ifndef FINAL_PROJECT_ANISHMEKA_AUTOMATED_FINADVISOR_APP_H
#define FINAL_PROJECT_ANISHMEKA_AUTOMATED_FINADVISOR_APP_H

#include "core/volatility-prediction/volatility_training_data_factory.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include <string>
#include <vector>
#include <filesystem>

using std::string;
using std::vector;
using std::map;

namespace finadvisor {

namespace visualizer {

/**
 * Allows user to visualize testing data after feeding training data into model and utilizing the K Nearest
 * Neighbors algorithm
 */
class AutomatedFinadvisorApp : public ci::app::App {
    public:
        AutomatedFinadvisorApp();
        void draw() override;
        void keyDown(ci::app::KeyEvent event) override;
        void DrawNextButton() const;
        void mouseDown(ci::app::MouseEvent event) override;
        friend ostream& operator<<(ostream& output, DailyPrice& price);
        static double GetWindowSize();
        static double GetMargin();
        static size_t GetLineWidth();
        void SketchAxes();
        void SketchCandleBody(const vector<DailyPrice>& daily_prices, double max_high_price, double min_low_price);
        friend bool operator<(const DailyPrice& first_price, const DailyPrice& second_price);
    private:
        constexpr static double kWindowSize_ = 875;
        constexpr static double kMargin_ = 100;
        string current_momentum_prediction_;
        string current_volatility_prediction_;
        double momentum_validation_accuracy_ = 93.73;
        double volatility_validation_accuracy_ = 90.03;
        const static size_t kLineWidth_ = 400;
        size_t month_index_;
        string price_summary_;
        const static size_t kAverageMonthlyTradingDays_ = 21;
        map<float, DailyPrice> prices_by_chart_location_;
};

}

}

#endif //FINAL_PROJECT_ANISHMEKA_AUTOMATED_FINADVISOR_APP_H
