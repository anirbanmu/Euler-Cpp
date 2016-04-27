#ifndef _1_DEF_H_
#define _1_DEF_H_

#include "../problem_base.h"

// Original prompt: Find the sum of all the multiples of 3 or 5 below 1000.

class Problem1 : public ProblemBase<1>
{
    public:
        wstring execute_core()
        {
            int y = 0;
            for (int i = 0; i < 409878; ++i)
            {
                y = i * i;
            }
            std::cout << y << std::endl;
            return L"UNSOLVED1";
        }
};

#endif