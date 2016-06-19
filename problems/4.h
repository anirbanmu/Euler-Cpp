#ifndef _4_DEF_H_
#define _4_DEF_H_

#include "../problem_base.h"

// Original prompt: A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
//
//                  Find the largest palindrome made from the product of two 3-digit numbers.


class Solver4 : public ProblemBase<4>
{
    public:
        string execute_core();
};

#endif