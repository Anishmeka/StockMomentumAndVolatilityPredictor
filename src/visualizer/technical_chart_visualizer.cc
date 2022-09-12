#include "visualizer/technical_chart_visualizer.h"
#include "cinder/gl/gl.h"
#include "core/momentum-prediction/momentum_training_data_factory.h"
#include "visualizer/automated_finadvisor_app.h"

namespace finadvisor {

namespace visualizer {

void TechnicalChartVisualizer::SketchAxes() const {
    ci::gl::color(ci::Color(1, 0, 1));
    ci::gl::drawLine(glm::vec2(AutomatedFinadvisorApp::GetWindowSize() / 20, 3 * AutomatedFinadvisorApp::GetWindowSize() / 4),
                     glm::vec2(AutomatedFinadvisorApp::GetWindowSize() / 20, (3 * AutomatedFinadvisorApp::GetWindowSize() / 4) -
                     AutomatedFinadvisorApp::GetLineWidth()));
    ci::gl::drawLine(glm::vec2((AutomatedFinadvisorApp::GetWindowSize() / 20) + AutomatedFinadvisorApp::GetLineWidth(),
                               3 * AutomatedFinadvisorApp::GetWindowSize() / 4),
                     glm::vec2(AutomatedFinadvisorApp::GetWindowSize() / 20, 3 * AutomatedFinadvisorApp::GetWindowSize() / 4));
}

void TechnicalChartVisualizer::SketchTrendLines(const vector<double> &price_differences, float horizontal_position,
                                                float vertical_position, float incremental_value) const {
    for (double price_difference : price_differences) {
        if (price_difference > 0) {
            ci::gl::color(ci::Color(1, 0, 0));
            ci::gl::drawLine(glm::vec2(horizontal_position, vertical_position),
                             glm::vec2(horizontal_position + incremental_value, vertical_position + incremental_value));
            horizontal_position += incremental_value;
            vertical_position += incremental_value;
        } else if (price_difference < 0) {
            ci::gl::color(ci::Color(0, 1, 0));
            ci::gl::drawLine(glm::vec2(horizontal_position, vertical_position),
                             glm::vec2(horizontal_position + incremental_value, vertical_position - incremental_value));
            horizontal_position += incremental_value;
            vertical_position -= incremental_value;
        } else {
            ci::gl::color(ci::Color(1, 1, 1));
            ci::gl::drawLine(glm::vec2(horizontal_position, vertical_position),
                             glm::vec2(horizontal_position + incremental_value, vertical_position));
            horizontal_position += incremental_value;
        }
    }
}

void TechnicalChartVisualizer::DrawTechnicalChart(const vector<string>& file_paths, size_t month_index) const {
    finadvisor::MomentumTrainingDataFactory momentum_factory;
    momentum_factory = momentum_factory.ValidateFiles(file_paths);
    vector<double> price_differences = momentum_factory.GetPriceDifferences(month_index);
    SketchAxes();
    SketchTrendLines(price_differences, static_cast<float>(AutomatedFinadvisorApp::GetWindowSize()) / 20,
                     static_cast<double>(AutomatedFinadvisorApp::GetWindowSize() / 4) * 3 - (0.5 * AutomatedFinadvisorApp::GetLineWidth()),
                     static_cast<float>(AutomatedFinadvisorApp::GetLineWidth()) / price_differences.size());
}

} // visualizer

} // finadvisor
