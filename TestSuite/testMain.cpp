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

    size_t epochYear = epoch.getYear();
    epoch.addYears(1);
    testPassed = assertEqual(epochYear + 1, epoch.getYear()) && testPassed;
    epoch.addYears(-1);
    testPassed = assertEqual(epochYear, epoch.getYear()) && testPassed;

    Date februaryTwentyNine2016(1456753041);
    size_t startingYear = februaryTwentyNine2016.getYear();
    size_t startingMonth = februaryTwentyNine2016.getMonth();
    februaryTwentyNine2016.addYears(1);
    testPassed = assertEqual(startingYear + 1, februaryTwentyNine2016.getYear()) && testPassed;
    testPassed = assertEqual(startingMonth + 1, februaryTwentyNine2016.getMonth()) && testPassed;
    testPassed = assertEqual(1, februaryTwentyNine2016.getDate()) && testPassed;

    // TODO: Test more edges
    // TODO: Date subtraction
    // TODO: Write testing helpers
    // TODO: Write better ctor
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