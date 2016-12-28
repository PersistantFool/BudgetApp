#pragma once
#include <memory>
#include <string>
#include <vector>

#include <time.h>

class Date
{
public:
    Date();
    Date(time_t timestamp);
    ~Date();

    size_t getYear() const;
    size_t getMonth() const;
    std::string getMonthString() const;
    size_t getDate() const;

    void addYears(int numberOfYears);
    void addMonths(int numberOfMonths);
    void addDays(int numberOfDays);

    std::string toString() const;
    bool operator==(const Date& rhs) const;
    bool operator!=(const Date& rhs) const;

private:
    bool isLeapYear() const;
    const static std::vector<std::string> monthNames;
    size_t daysPerMonth(size_t month) const;
    struct tm mDatetime;
};

std::ostream& operator<<(std::ostream& stream, const Date& rhs);
