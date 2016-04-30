#include <iostream>
#include <vector>
#include <tuple>
#include "4.h"

using namespace std;

struct num_props
{
    vector<unsigned char> digits;
    unsigned long high_mask;
};

num_props get_digits(unsigned long n)
{
    num_props prop;

    auto& digits = prop.digits;
    unsigned long mask;
    for (mask = 10; n > 0; mask = mask * 10)
    {
        const unsigned long place_value = n % mask;
        digits.push_back(place_value / (mask / 10));
        n -= place_value;
    }

    // Place mask back at highest place found
    mask = mask / 10 / 10;

    prop.high_mask = mask;
    return prop;
}

unsigned long reverse(unsigned long n)
{
    const auto prop = get_digits(n);

    const auto& digits = prop.digits;
    auto mask = prop.high_mask;

    unsigned long reversed = 0;
    for (unsigned i = 0; i < digits.size(); ++i, mask = mask / 10)
    {
        reversed += digits[i] * mask;
    }
    return reversed;
}

unsigned long pow(unsigned long b, unsigned long p)
{
    auto r = 1;
    for (auto i = 0; i < p; ++i)
    {
        r *= b;
    }
    return r;
}

unsigned long highest_palindrome(unsigned digits)
{
    const unsigned long limit = pow(10, digits);

    unsigned long highest = 0;
    for (unsigned long i = 0; i < limit; ++i)
    {
        // Everything under is already done by outer loop.
        for (unsigned long j = i; j < limit; ++j)
        {
            const auto product = i * j;
            if (product == reverse(product))
            {
                highest = max(highest, product);
            }
        }
    }

    return highest;
}

string Solver4::execute_core()
{
    return to_string(highest_palindrome(3));
}