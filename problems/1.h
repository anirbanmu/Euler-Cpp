#ifndef _1_DEF_H_
#define _1_DEF_H_

#include "../problem_base.h"

// Original prompt: Find the sum of all the multiples of 3 or 5 below 1000.

template <bool skip> unsigned accumulate(unsigned incr, unsigned limit, unsigned ignore = 0)
{
    unsigned acc = incr;
    for (unsigned i = acc + incr; i < limit; i = i + incr)
    {
        if (skip)
        {
            if (i % ignore == 0) continue;
        }
        acc += i;
    }
    return acc;
}

class Problem1 : public ProblemBase<1>
{
    public:
        string execute_core()
        {
            return std::to_string(accumulate<false>(3, 1000) + accumulate<true>(5, 1000, 3 * 5));
        }

        ~Problem1()
        {
        }
};

#endif