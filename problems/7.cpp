#include <vector>
#include <algorithm>
#include <cmath>

#include "7.h"

using namespace std;

unsigned long generate_nth_prime(unsigned index)
{
    vector<unsigned long> lesser_primes;

    for (unsigned long c = 2; lesser_primes.size() != index; ++c)
    {
        const auto primes_end = upper_bound(lesser_primes.begin(), lesser_primes.end(), static_cast<unsigned long>(sqrt(double(c))));
        if (any_of(lesser_primes.begin(), primes_end, [=](const auto& p){ return c % p == 0; }))
        {
            continue;
        }
        lesser_primes.emplace_back(c);
    }

    return lesser_primes.back();
}