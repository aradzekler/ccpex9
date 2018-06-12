#include "TestCase.hpp"

ostream& operator<<(ostream& os, TestCase& obj)
{
    return obj.stream;
}

void TestCase::print()
{
    stream << testcase << ": " << failed << " tests failed, " << passed << " tests passed, " << total << " total." << endl << endl;
    cout << *this;
}
