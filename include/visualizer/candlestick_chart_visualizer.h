#ifndef AUTOMATED_FINADVISOR_CANDLESTICK_CHART_VISUALIZER_H
#define AUTOMATED_FINADVISOR_CANDLESTICK_CHART_VISUALIZER_H

#include <vector>
#include <string>
#include "core/volatility-prediction/volatility_training_data_factory.h"

using std::string;
using std::vector;

namespace finadvisor {

namespace visualizer {

class CandlestickChartVisualizer {
    public:
        /**
         * Renders candlestick chart on external screen.
         *
         * @param file_paths paths of data files
         * @param month_index index of current month within vector
         */
        void DrawCandlestickChart(const vector<string> file_paths, size_t month_index) const;
        /**
         * Renders candlestick wicks on external screen.
         *
         * @param horizontal_position horizontal position of wick
         * @param vertical_position vertical position of wick
         * @param incremental_value horizontal separation between each wick
         * @param scaled_high_price standardized daily high price
         * @param scaled_low_price standardized daily low price
         */
        void SketchCandleWicks(float horizontal_position, float vertical_position, float incremental_value,
                               float scaled_high_price, float scaled_low_price) const;
        /**
         * Renders candlestick body on external screen.
         *
         * @param daily_prices Vector containing price summaries
         * @param max_high_price Highest of high prices
         * @param min_low_price Lowest of low prices
         */
        void SketchCandleBody(const vector<DailyPrice>& daily_prices, double max_high_price, double min_low_price);
        friend bool operator<(const DailyPrice& first_price, const DailyPrice& second_price);
        void SketchAxes() const;
        map<float, DailyPrice> GetPricesByChartLocation();
        static size_t GetAverageMonthlyTradingDays();
    private:
        map<float, DailyPrice> prices_by_chart_location_;

    void SketchCandleBody(const vector<DailyPrice> &daily_prices, double max_high_price, double min_low_price) const;
};

}

}


#endif //AUTOMATED_FINADVISOR_CANDLESTICK_CHART_VISUALIZER_H
