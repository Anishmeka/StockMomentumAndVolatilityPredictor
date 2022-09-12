#ifndef AUTOMATED_FINADVISOR_VOLATILITY_TRAINING_DATA_FACTORY_H
#define AUTOMATED_FINADVISOR_VOLATILITY_TRAINING_DATA_FACTORY_H

#include "core/volatility-prediction/volatility_calculator.h"
#include <string>
#include <fstream>
#include <vector>
#include <map>

using std::string;
using std::istream;
using std::vector;
using std::ostream;
using std::map;

struct DailyPrice {
    double opening_price;
    double closing_price;
    double high_price;
    double low_price;
};

namespace finadvisor {

class VolatilityTrainingDataFactory {
    public:
        /**
         * Inserts members variables into output txt file representing training data.
         *
         * @param input ostream for insertion purposes
         * @param factory instance of VolatilityTrainingDataFactory class
         * @return ostream representing VolatilityTrainingDataFactory
         */
        friend istream& operator>>(istream& input, VolatilityTrainingDataFactory& factory);
        /**
         * Invokes extraction operator.
         *
         * @param file_paths path of csv file for extraction purposes
         * @return updated instance of VolatilityTrainingDataFactory class with member variable values extracted from txt file
         */
        VolatilityTrainingDataFactory ValidateFiles(const vector<string>& file_paths) const;
        friend ostream& operator<<(ostream& input, VolatilityTrainingDataFactory& factory);
        /**
         * Creates output file and inserts values that constitute training data set.
         *
         * @param factory instance of VolatilityTrainingDataFactory class
         * @return file path of output file
         */
        string WriteToOutputFile(VolatilityTrainingDataFactory& factory);
        DailyPrice GetDailyPrice(size_t vector_index);
        Volatility GetVolatility(size_t map_index);
        vector<double> GetStandardizedQuartilePrices(size_t map_index);
    private:
        /**
         * Adds DailyPrice struct with updated values to daily prices vector.
         *
         * @param line File line of txt file.
         */
        void UpdateDailyPrices(const string& line);
        vector<DailyPrice> daily_prices_;
        map<vector<double>, Volatility> volatility_by_standardized_quartile_price_;
        vector<double> quartile_prices_;
        const static size_t kHighPriceIndex_ = 2;
        const static size_t kLowPriceIndex_ = 3;
};

const static string kVolatilityOutputFilePath_ = "data/volatilitytrainingdata.txt";
const static string kVolatilityTrainingDataCharacters_ = "+-";
}

#endif //AUTOMATED_FINADVISOR_VOLATILITY_TRAINING_DATA_FACTORY_H
