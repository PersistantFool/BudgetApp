#include "Date.h"
#include <iostream>
#include <string>

template <typename T>
bool assertEqual(T lhs, T rhs, const std::string& message="")
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

int main(int argc, char** argv)
{
    Date epoch(0);
    Date christmasEve2016(1482624068);
    assertEqual(epoch.getYear(), static_cast<size_t>(1969));
    assertEqual(christmasEve2016.getYear(), static_cast<size_t>(2016));

    assertEqual(epoch.getMonth(), static_cast<size_t>(12));
    assertEqual(christmasEve2016.getMonth(), static_cast<size_t>(12));

    assertEqual(epoch.getDate(), static_cast<size_t>(31));
    assertEqual(christmasEve2016.getDate(), static_cast<size_t>(24));

    assertEqual(epoch.toString(), std::string("31 December 1969"));
    assertEqual(christmasEve2016.toString(), std::string("24 December 2016"));

    Date today;
    std::cerr << today.toString() << std::endl;

    return 0;
}