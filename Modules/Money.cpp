#include "stdafx.h"
#include "Money.h"


Money::Money(double amount)
{
    mValueInCents = static_cast<int>(amount * 100);
}


Money::~Money()
{
}

std::string Money::toString() const
{
    std::string dollarValue = std::to_string(std::abs(mValueInCents / 100));
    std::string centValue = std::to_string(std::abs(mValueInCents % 100));

    if (centValue.size() == 1)
    {
        centValue = "0" + centValue;
    }

    std::string sign = mValueInCents < 0 ? "-" : "";

    // TODO: Add comma thousands separator

    return sign + "$" + dollarValue + "." + centValue;
}

double Money::getValue() const
{
    return mValueInCents / 100.0;
}

bool Money::operator==(const Money& rhs) const
{
    return mValueInCents == rhs.mValueInCents;
}

bool Money::operator!=(const Money& rhs) const
{
    return !(*this == rhs);
}

Money& Money::operator+=(const Money& rhs)
{
    mValueInCents += rhs.mValueInCents;
    return *this;
}

const Money Money::operator+(const Money& rhs) const
{
    Money result(getValue());
    return result += rhs;
}

Money& Money::operator-=(const Money& rhs)
{
    mValueInCents -= rhs.mValueInCents;
    return *this;
}

const Money Money::operator-(const Money& rhs) const
{
    Money result(getValue());
    return result -= rhs;
}

std::ostream& operator<<(std::ostream& stream, const Money& rhs)
{
    return stream << rhs.toString();
}
