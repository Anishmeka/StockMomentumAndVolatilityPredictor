#include "visualizer/candlestick_chart_visualizer.h"
#include "core/volatility-prediction/volatility_training_data_factory.h"
#include <float.h>


namespace finadvisor {

namespace visualizer {

map<float, DailyPrice> CandlestickChartVisualizer::GetPricesByChartLocation() {
    return prices_by_chart_location_;
}


void CandlestickChartVisualizer::SketchCandleBody(const vector<DailyPrice>& daily_prices, double max_high_price,
                                                  double min_low_price) {
}

void CandlestickChartVisualizer::SketchCandleWicks(float horizontal_position, float vertical_position,
                                                   float incremental_value, float scaled_high_price,
                                                   float scaled_low_price) const {
}

void CandlestickChartVisualizer::DrawCandlestickChart(const vector<string> file_paths, size_t month_index) const {
}

}

}