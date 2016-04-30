#include "3.h"

long greatest_prime_factor(long n)
{
    long remaining = n;
    long factor = 2;
    while (factor * factor < remaining)
    {
        if (remaining % factor == 0)
        {
            remaining = remaining / factor;
            continue;
        }
        factor += 1;
    }

    return remaining;
}