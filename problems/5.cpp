#include <vector>
#include <algorithm>
#include <numeric>

#include "5.h"
#include "util.h"

using namespace std;

vector<unsigned long> primes_in_range(const tuple<unsigned long, unsigned long>& range)
{
    vector<unsigned long> v;
    for (auto i = get<0>(range); i <= get<1>(range); ++i)
    {
        if (is_prime(i))
        {
            v.emplace_back(i);
        }
    }
    return v;
}

unsigned long lower_bound_product(const tuple<unsigned long, unsigned long>& range)
{
    const auto primes = primes_in_range(range);
    return accumulate(primes.begin(), primes.end(), 1, multiplies<unsigned long>());
}

unsigned long upper_bound_product(const tuple<unsigned long, unsigned long>& range)
{
    unsigned long p = 1;
    for (auto i = get<0>(range); i <= get<1>(range); ++i)
    {
        p *= i;
    }
    return p;
}

bool evenly_divisible(unsigned long product, const tuple<unsigned long, unsigned long>& range)
{
    for (auto i = get<0>(range); i <= get<1>(range); ++i)
    {
        if (product % i != 0)
        {
            return false;
        }
    }
    return true;
}

unsigned long smallest_evenly_divisible(const tuple<unsigned long, unsigned long>& range)
{
    const auto lower_bound = lower_bound_product(range);
    const auto upper_bound = upper_bound_product(range);
    for (auto i = lower_bound; i < upper_bound; i += lower_bound)
    {
        if (evenly_divisible(i, range))
        {
            return i;
        }
    }
    return upper_bound;
}
