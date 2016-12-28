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

void Date::addYears(int numberOfYears)
{
    if (isLeapYear() &&    // This is a leap-year
        numberOfYears % 4 != 0 &&        // Target year is not leap-year
        mDatetime.tm_mday == 29)         // This is a leap-day
    {
        addDays(1);
    }
    mDatetime.tm_year += numberOfYears;
}

// TOOD: Handle negative days
void Date::addDays(int numberOfDays)
{
    int daysRemaining = numberOfDays + getDate() - daysPerMonth(getMonth());
    if (daysRemaining <= 0)
    {
        mDatetime.tm_mday += numberOfDays;
    }
    else
    {
        daysRemaining -= (daysPerMonth(getMonth()) - getDate());
        mDatetime.tm_mday = 0;
        addMonths(1);
        while (daysRemaining > static_cast<int>(daysPerMonth(getMonth())))
        {
            daysRemaining -= daysPerMonth(getMonth());
            addMonths(1);
        }

        mDatetime.tm_mday += daysRemaining;
    }
}

void Date::addMonths(int numberOfMonths)
{
    mDatetime.tm_mon += numberOfMonths;
    while (getMonth() < 0)
    {
        addYears(-1);
        mDatetime.tm_mon += 12;
    }
    while (getMonth() > 11)
    {
        addYears(1);
        mDatetime.tm_mon -= 12;
    }
}

size_t Date::daysPerMonth(size_t month) const
{
    if (month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11)
    {
        return 31;
    }
    if (month == 3 || month == 5 || month == 8)
    {
        return 30;
    }
    if (month > 11)
    {
        return 0;
        // TODO: throw an exception
    }

    // This is February
    if (isLeapYear())
    {
        return 29;
    }
    return 28;
}

bool Date::isLeapYear() const
{
    return getYear() % 4 == 0;
}

