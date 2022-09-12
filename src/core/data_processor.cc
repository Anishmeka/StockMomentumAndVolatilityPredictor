#include "core/data_processor.h"

vector<string> DataProcessor::Split(const string& input, const string& delimiter) const {
    // Code below was derived from:
    // https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
    vector<std::string> tokens;
    size_t previous = 0;
    size_t position = 0;
    do {
        position = input.find(delimiter, previous);
        if (position == std::string::npos) {
            position = input.length();
        }
        std::string token = input.substr(previous, position - previous);
        if (!token.empty()) {
            tokens.push_back(token);
        }
        previous = position + delimiter.length();
    } while (position < input.length() && previous < input.length());
    return tokens;
}