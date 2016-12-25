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

    std::string toString() const;
    bool operator==(const Date& rhs) const;
    bool operator!=(const Date& rhs) const;

private:
    const static std::vector<std::string> monthNames;
    struct tm mDatetime;
};

std::ostream& operator<<(std::ostream& stream, const Date& rhs);
