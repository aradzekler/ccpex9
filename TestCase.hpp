#pragma once
#include <iostream>
#include <sstream>

using namespace std;

class TestCase
{

  public:
    string testcase; // case name
    ostream os;
    int total, failed, passed;
    friend ostream& operator<<(ostream& os, TestCase& obj);
    void print();

    TestCase(string name, ostream &os) // constructor
    {
        testcase = name;
        stream = os.rdbuf();
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
        if (ss.str() == b)
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
        if ((*func)(a) == b)
        {
            passed++;
        }
        else
        {
            cout << testcase << " Failed. Failure in test number " << total << ". Function should return " << b << " but returned " << (*func)(a) << "." << endl;
            failed++;
        }
        return *this;
    }
};
