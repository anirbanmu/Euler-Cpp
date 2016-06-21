#include <vector>
#include <algorithm>

#include "7.h"

using namespace std;

unsigned long generate_nth_prime(unsigned index)
{
    vector<unsigned long> lesser_primes;

    for (unsigned long c = 2; lesser_primes.size() != index; ++c)
    {
        if (any_of(lesser_primes.begin(), lesser_primes.end(), [=](const auto& p){ return c % p == 0; }))
        {
            continue;
        }
        lesser_primes.emplace_back(c);
    }

    return lesser_primes.back();
}