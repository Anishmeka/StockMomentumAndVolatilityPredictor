#ifndef AUTOMATED_FINADVISOR_MOMENTUM_TRAINING_DATA_FACTORY_H
#define AUTOMATED_FINADVISOR_MOMENTUM_TRAINING_DATA_FACTORY_H

#include <string>
#include <vector>
#include <map>
#include "core/momentum-prediction/momentum_calculator.h"

using std::string;
using std::wstring;
using std::vector;
using std::istream;
using std::ostream;
using std::map;

namespace finadvisor {

class MomentumTrainingDataFactory {
    public:
        /**
         * Extracts values from input csv file into member variables of MomentumTrainingDataFactory class.
         *
         * @param input istream representing txt file for extraction purposes
         * @param model instance of MomentumTrainingDataFactory class
         * @return istream representing MomentumTrainingDataFactory
         */
        friend istream& operator>>(istream& input, MomentumTrainingDataFactory& factory);
        /**
         * Invokes extraction operator.
         *
         * @param file_paths path of csv file for extraction purposes
         * @return updated instance of MomentumTrainingDataFactory class with member variable values extracted from txt file
         */
        MomentumTrainingDataFactory ValidateFiles(const vector<string>& file_paths) const;
        /**
         * Inserts members variables into output txt file representing training data.
         *
         * @param input ostream for insertion purposes
         * @param factory instance of MomentumTrainingDataFactory class
         * @return ostream representing MomentumTrainingDataFactory
         */
        friend ostream& operator<<(ostream& input, MomentumTrainingDataFactory& factory);
        /**
         * Creates output file and inserts values that constitute training data set.
         *
         * @param factory instance of MomentumTrainingDataFactory class
         * @return file path of output file
         */
        string WriteToOutputFile(MomentumTrainingDataFactory& factory);
        Momentum GetMomentum(size_t map_index);
        std::vector<double> GetPriceDifferences(size_t map_index);
        static size_t GetClosingPriceIndex();
        static size_t GetOpeningPriceIndex();
    private:
        vector<double> price_differences_;
        map<vector<double>, Momentum> momentum_by_price_difference_;
        const static size_t kClosingPriceIndex_ = 4;
        const static size_t kOpeningPriceIndex_ = 1;
};

const static string kParseCharacter_ = ",";
const static string kNewLineCharacter_ = "\n";
const static string kMomentumTrainingDataCharacters_ = "↗↘-";
const static string kUpwardTrendCharacter_ = "↗";
const static string kDownwardTrendCharacter_ = "↘";
const static string kStaticTrendCharacter_ = "-";
const static string kMomentumTrainingDataUnicode_ = "0x7ff84393afe0,0x7faad7c3e4d0,0x7ffee0aaaffc";
const static string kMomentumOutputFilePath_ = "data/momentumtrainingdata.txt";
}

#endif //AUTOMATED_FINADVISOR_MOMENTUM_TRAINING_DATA_FACTORY_H
