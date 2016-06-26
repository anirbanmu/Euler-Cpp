#ifndef _PROBLEM_BASE_H_
#define _PROBLEM_BASE_H_

#include <string>
#include <tuple>
#include <chrono>

using std::tuple;
using std::make_tuple;
using std::string;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;
using std::chrono::high_resolution_clock;

class ProblemInterface
{
    public:
        virtual tuple<unsigned, string, nanoseconds> execute() = 0;
        virtual ~ProblemInterface()
        {
        }
};

template<unsigned problem_number> class ProblemBase : public ProblemInterface
{
    const unsigned problem_number_;
    public:
        ProblemBase() : problem_number_(problem_number)
        {
        }

        // Euler project problem number, result as a string, duration taken for calculation
        tuple<unsigned, string, nanoseconds> execute()
        {
            const auto before = high_resolution_clock::now();
            const auto result = execute_core();
            const auto after = high_resolution_clock::now();
            return make_tuple(problem_number_, result, duration_cast<nanoseconds>(after - before));
        }

        virtual string execute_core() = 0;

        virtual ~ProblemBase()
        {
        }
};

#endif