#include "3.h"

long greatest_prime_factor(long n)
{
    long remaining = n;
    long greatest_factor = 0;
    long factor = 2;
    while (factor * factor <= remaining)
    {
        if (remaining % factor == 0)
        {
            remaining = remaining / factor;
            greatest_factor = factor;
            continue;
        }
        factor += factor == 2 ? 1 : 2;
    }

    return greatest_factor < remaining ? remaining : greatest_factor;
}