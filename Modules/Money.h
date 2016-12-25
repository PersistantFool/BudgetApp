#pragma once

#include <string>

class Money
{
public:
    Money(double amount=0);
    ~Money();

    std::string toString() const;
    double getValue() const;

    bool operator==(const Money& rhs) const;
    bool operator!=(const Money& rhs) const;

    Money& operator+=(const Money& rhs);
    const Money operator+(const Money& rhs) const;

    Money& operator-=(const Money& rhs);
    const Money operator-(const Money& rhs) const;

private:
    int mValueInCents;
};

std::ostream& operator<<(std::ostream& stream, const Money& rhs);
