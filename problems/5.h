#ifndef _5_DEF_H_
#define _5_DEF_H_

#include <tuple>

#include "../problem_base.h"

// Original prompt: What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

unsigned long smallest_evenly_divisible(const std::tuple<unsigned long, unsigned long>& range);

class Solver5 : public ProblemBase<5>
{
    public:
        string execute_core()
        {
            return std::to_string(smallest_evenly_divisible(std::tuple<unsigned long, unsigned long>(1, 20)));
        }
        ~Solver5()
        {
        }
};

#endif