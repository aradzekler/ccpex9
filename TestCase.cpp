#include "TestCase.hpp"



TestCase::TestCase(string name, ostream &os):stream(os.rdbuf()) // constructor
{
    testcase = name;
    total = 0;
    failed = 0;
    passed = 0;
}

ostream& operator<<(ostream& os, TestCase& obj)
{
    return obj.stream;
}

void TestCase::print()
{
    stream << testcase << ": " << failed << " tests failed, " << passed << " tests passed, " << total << " total." << endl << endl;
    cout << *this;
}
