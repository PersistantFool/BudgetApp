#include "stdafx.h"
#include "Date.h"
#include <vector>

Date::Date()
{
    time_t currentTimestamp = time(NULL);
    localtime_s(&mDatetime, &currentTimestamp);
}

Date::Date(time_t timestamp)
{
    localtime_s(&mDatetime, &timestamp);
}

Date::~Date()
{
}

size_t Date::getYear()
{
    static const size_t YEAR_OFFSET = 1900;
    return mDatetime.tm_year + YEAR_OFFSET;
}

size_t Date::getMonth()
{
    static const size_t MONTH_OFFSET = 1;
    return mDatetime.tm_mon + MONTH_OFFSET;
}

size_t Date::getDate()
{
    return mDatetime.tm_mday;
}

std::string Date::toString()
{
    return std::to_string(getDate()) + " " + getMonthString() + " " + std::to_string(getYear());
}

std::string Date::getMonthString()
{
    std::vector<std::string> monthNames(13);
    monthNames[0] = "";
    monthNames[1] = "January";
    monthNames[2] = "February";
    monthNames[3] = "March";
    monthNames[4] = "April";
    monthNames[5] = "May";
    monthNames[6] = "June";
    monthNames[7] = "July";
    monthNames[8] = "August";
    monthNames[9] = "September";
    monthNames[10] = "October";
    monthNames[11] = "November";
    monthNames[12] = "December";
    return monthNames[getMonth()];
}
