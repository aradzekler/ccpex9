#include "TestCase.hpp"

ostream& operator<<(ostream& os, TestCase& obj)
{
    return obj.stream;
}
