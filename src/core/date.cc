#include "core/date.h"
#include "core/data_processor.h"

using std::stoi;

Date::Date(const string& date) {
    DataProcessor processor;
    vector<string> date_components = processor.Split(date, "-");
    year_ = stoi(date_components[0]);
    month_ = stoi(date_components[1]);
    day_ = stoi(date_components[2]);
}

size_t Date::GetDay() const {
    return day_;
}

size_t Date::GetMonth() const {
    return month_;
}

size_t Date::GetYear() const {
    return year_;
}