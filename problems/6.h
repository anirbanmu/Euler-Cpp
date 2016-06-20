#ifndef _6_DEF_H_
#define _6_DEF_H_

#include <tuple>

#include "../problem_base.h"

// Original prompt: The sum of the squares of the first ten natural numbers is,
//                      1^2 + 2^2 + ... + 10^2 = 385
//
//                  The square of the sum of the first ten natural numbers is,
//                      (1 + 2 + ... + 10)^2 = 55^2 = 3025
//
//                  Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
//
//                  Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

class Solver6 : public ProblemBase<6>
{
    public:
        string execute_core()
        {
            const auto range = tuple<unsigned long, unsigned long>(1, 100);
            const auto a = square_of_sum(range);
            const auto b = sum_of_squares(range);
            return std::to_string(std::max(a, b) - std::min(a, b));
        }

    private:
        unsigned long sum_of_squares(std::tuple<unsigned long, unsigned long> range);
        unsigned long square_of_sum(std::tuple<unsigned long, unsigned long> range);
};

#endif