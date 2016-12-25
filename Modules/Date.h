#pragma once
#include <memory>
#include <string>

#include <time.h>

class Date
{
public:
    Date();
    Date(time_t timestamp);
    ~Date();

    size_t getYear();
    size_t getMonth();
    size_t getDate();

    std::string toString();

private:
    struct tm mDatetime;
    std::string getMonthString();
};

