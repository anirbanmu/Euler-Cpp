#include "3.h"

bool definitely_not_prime(long n)
{
    if (n == 2 || n == 3) return true;

    static const std::vector<long> v{2,3};
    return std::any_of(v.begin(), v.end(), [=](auto f){ return n % f == 0; });
}

long is_prime(long n)
{
    if (definitely_not_prime(n)) return false;
    for (long i = 2; i <= static_cast<long>(std::sqrt(n)); ++i)
    {
        if (n % i == 0) return false;
    }
    return true;
}

long greatest_prime_factor(long n)
{
    const long limit = static_cast<long>(std::sqrt(n));
    for (long cur = limit; cur > 1; cur--)
    {
        if (n % cur == 0 && is_prime(cur)) return cur;
    }
    return 1;
}