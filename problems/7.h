#ifndef _7_DEF_H_
#define _7_DEF_H_

#include "../problem_base.h"

// Original prompt: By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
//                  What is the 10001st prime number?

// 1 based index
unsigned long generate_nth_prime(unsigned index);

class Solver7 : public ProblemBase<7>
{
    public:
        string execute_core()
        {
            return std::to_string(generate_nth_prime(10001));
        }

        ~Solver7()
        {
        }
};

#endif