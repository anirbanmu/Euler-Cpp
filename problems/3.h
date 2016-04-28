#ifndef _3_DEF_H_
#define _3_DEF_H_

#include <algorithm>
#include <cmath>

#include "../problem_base.h"

// Original prompt: What is the largest prime factor of the number 600851475143?

long greatest_prime_factor(long n);

class Problem3 : public ProblemBase<3>
{
    public:
        wstring execute_core()
        {
            return std::to_wstring(greatest_prime_factor(600851475143));
        }
};

#endif