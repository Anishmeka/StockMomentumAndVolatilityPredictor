#ifndef AUTOMATED_FINADVISOR_TECHNICAL_CHART_VISUALIZER_H
#define AUTOMATED_FINADVISOR_TECHNICAL_CHART_VISUALIZER_H

#include <vector>
#include <string>

using std::string;

using std::vector;

namespace finadvisor {

namespace visualizer {

class TechnicalChartVisualizer {
    public:
        /**
         * Renders axes of technical chart on external screen
         */
        void SketchAxes() const;
        /**
         * Renders lines of technical chart on external screen.
         *
         * @param price_differences Vector containing differences between opening and closing prices
         * @param horizontal_position Horizontal position of line
         * @param vertical_position Vertical position of line
         * @param incremental_value Horizontal separation between each line
         */
        void SketchTrendLines(const vector<double>& price_differences, float horizontal_position,
                              float vertical_position, float incremental_value) const;
        /**
         * Renders technical chart on external screen
         *
         * @param file_paths Vector containing data paths
         * @param month_index Index of current month in vector
         */
        void DrawTechnicalChart(const vector<string>& file_paths, size_t month_index) const;
};

} // visualizer

} // finadvisor

#endif //AUTOMATED_FINADVISOR_TECHNICAL_CHART_VISUALIZER_H
