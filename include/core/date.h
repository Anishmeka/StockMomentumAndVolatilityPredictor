#ifndef AUTOMATED_FINADVISOR_DATE_H
#define AUTOMATED_FINADVISOR_DATE_H

#include <string>

using std::string;

class Date {
    public:
        Date(const string& date);
        size_t GetMonth() const;
        size_t GetYear() const;
        size_t GetDay() const;
    private:
        size_t month_;
        size_t year_;
        size_t day_;
};


#endif //AUTOMATED_FINADVISOR_DATE_H
