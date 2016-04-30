#ifndef _2_DEF_H_
#define _2_DEF_H_

#include "../problem_base.h"

class Problem2 : public ProblemBase<2>
{
    public:
        string execute_core()
        {
            unsigned acc = 0;
            unsigned l0 = 1, l1 = 2;
            while (l1 < 4000000)
            {
                acc += l1 % 2 == 0 ? l1 : 0;

                const unsigned sum = l0 + l1;
                l0 = l1;
                l1 = sum;
            }
            return std::to_string(acc);
        }
};

#endif