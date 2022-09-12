#ifndef AUTOMATED_FINADVISOR_DATA_PROCESSOR_H
#define AUTOMATED_FINADVISOR_DATA_PROCESSOR_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class DataProcessor {
    public:
        /**
         * Splits input string into vector based upon the delimiter
         *
         * @param input input string
         * @param delimiter character input string is separated on
         * @return vector containing string separated by delimiter
         */
        vector<string> Split(const string& input, const string& delimiter) const;
};


#endif //AUTOMATED_FINADVISOR_DATA_PROCESSOR_H
