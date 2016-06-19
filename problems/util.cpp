#include <vector>
#include <algorithm>
#include <iostream>
#include <type_traits>

#include "util.h"

using namespace std;

const vector<unsigned long> common_primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

bool is_prime(unsigned long n)
{
    if (n < 2)
    {
        return false;
    }

    if (find(common_primes.begin(), common_primes.end(), n) != common_primes.end())
    {
        return true;
    }

    for (const auto& c : common_primes)
    {
        if (n % c == 0)
        {
            return false;
        }
    }

    if (n < common_primes.back())
    {
        cout << "PROBLEM" << endl;
    }

    for (unsigned long i = n - 1; i > common_primes.back(); --i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}