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

size_t Date::getYear() const
{
    static const size_t YEAR_OFFSET = 1900;
    return mDatetime.tm_year + YEAR_OFFSET;
}

size_t Date::getMonth() const
{
    return mDatetime.tm_mon;
}

size_t Date::getDate() const
{
    return mDatetime.tm_mday;
}

std::string Date::toString() const
{
    return std::to_string(getDate()) + " " + getMonthString() + " " + std::to_string(getYear());
}

const std::vector<std::string> Date::monthNames = {
    "January",
    "February",
    "March",
     "April",
     "May",
     "June",
     "July",
     "August",
     "September",
     "October",
     "November",
     "December"
};

std::string Date::getMonthString() const
{
    return monthNames[getMonth()];
}

bool Date::operator==(const Date& rhs) const
{
    return getYear() == rhs.getYear() &&
        getMonth() == rhs.getMonth() &&
        getDate() == rhs.getDate();
}

bool Date::operator!=(const Date& rhs) const
{
    return !(*this == rhs);
}

std::ostream& operator<<(std::ostream& stream, const Date& rhs)
{
    return stream << rhs.toString();
}
