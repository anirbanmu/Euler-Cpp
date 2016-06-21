#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

#include "util.h"

using namespace std;

const vector<unsigned long> common_primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

bool is_prime(unsigned long n, const vector<unsigned long>& known_lesser_primes)
{
    if (n < 2)
    {
        return false;
    }

    if (find(known_lesser_primes.begin(), known_lesser_primes.end(), n) != known_lesser_primes.end())
    {
        return true;
    }

    for (const auto& c : known_lesser_primes)
    {
        if (n % c == 0)
        {
            return false;
        }
    }

    for (unsigned long i = static_cast<unsigned long>(sqrt(static_cast<long double>(n))); i > known_lesser_primes.back(); --i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

bool is_prime(unsigned long n)
{
    return is_prime(n, common_primes);
}