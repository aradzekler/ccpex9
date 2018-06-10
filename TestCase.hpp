#pragma once
#include <iostream>
using namespace std;

class TestCase
{

  public:
    string testcase; // case name
    int total, failed, passed;

    TestCase(string name, ostream &os) // constructor
    {
        testcase = name;
        total = 0;
        failed = 0;
        passed = 0;
    }

    template <typename T>
    TestCase &check_equal(T a, T b)
    {
        total++;
        if (a == b)
        {
            passed++; // is equal
        }
        else
        {
            cout << testcase << " Failed. Failure in test number " << total << ". " << a << " is NOT equal to " << b << "." << endl;
            failed++;
        }
        return *this;
    }

    template <typename T>
    TestCase &check_different(T a, T b)
    {
        total++;
        if (a != b)
        {
            passed++; // is not equal
        }
        else
        {
            cout << testcase << " Failed. Failure in test number " << total << ". " << a << " is equal to " << b << "." << endl;
            failed++;
        }
        return *this;
    }

    template <typename T>
    TestCase &check_output(T a, string b)
    {
        total++;
        stringstream ss;
        ss << a;
        if (ss.str().equals(b)
        {
            passed++;
        }
        else
        {
            cout << testcase << " Failed. Failure in test number " << total << ". String should be " << b << " but is " << ss.str() << endl;
            failed++;
        }
        return *this;
    }

    template <typename T, typename Function>
    TestCase &check_function(Function func, T a, int b)
    {
        total++;
        if ((*fun)(a) == b)
        {
            passed++;
        }
        else
        {
            cout << testcase << " Failed. Failure in test number " << total << ". Function should return " << b << " but returned " << (*fun)(a) << "." << endl;
            failed++;
        }
        return *this;
    }

    void print()
    {
        cout << testcase << ": " << failed << " failed, " << passed << " passed, " << total << " total." << endl;
    }
};
