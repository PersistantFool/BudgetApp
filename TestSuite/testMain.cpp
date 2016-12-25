#include "Date.h"
#include "Money.h"

#include <iostream>
#include <string>

template <typename T, typename M>
bool assertEqual(T lhs, M rhs, const std::string& message="")
{
    if (lhs != rhs)
    {
        if (!message.empty())
        {
            std::cerr << message.c_str() << ": ";
        }
        std::cerr << lhs << " != " << rhs << std::endl;
        return false;
    }
    return true;
}

bool testDate()
{
    bool testPassed = true;

    Date epoch(0);
    Date christmasEve2016(1482624068);
    testPassed = assertEqual(epoch.getYear(), 1969) && testPassed;
    testPassed = assertEqual(christmasEve2016.getYear(), 2016) && testPassed;

    testPassed = assertEqual(epoch.getMonth(), 11) && testPassed;
    testPassed = assertEqual(christmasEve2016.getMonth(), 11) && testPassed;

    testPassed = assertEqual(epoch.getDate(), 31) && testPassed;
    testPassed = assertEqual(christmasEve2016.getDate(), 24) && testPassed;

    testPassed = assertEqual(epoch.toString(), "31 December 1969") && testPassed;
    testPassed = assertEqual(christmasEve2016.toString(), "24 December 2016") && testPassed;

    Date todayNoArguments;
    Date today(time(NULL));

    testPassed = assertEqual(todayNoArguments, today) && testPassed;

    // TODO: Increment Dates
    return testPassed;
}

bool testMoney()
{
    bool testPassed = true;
    Money noMoney;
    Money money(3.5);
    Money cents(-.09);

    testPassed = assertEqual(money.toString(), "$3.50") && testPassed;
    testPassed = assertEqual(noMoney.toString(), "$0.00") && testPassed;
    testPassed = assertEqual(cents.toString(), "-$0.09") && testPassed;

    testPassed = assertEqual(money + cents, Money(3.41)) && testPassed;
    testPassed = assertEqual(money - cents, Money(3.59)) && testPassed;
    testPassed = assertEqual(money - 1.00, Money(2.50)) && testPassed;

    // TODO: Add comma thousands separator

    return testPassed;
}

int main(int argc, char** argv)
{
    bool success = testDate();
    success = testMoney() && success;
    return 0;
}