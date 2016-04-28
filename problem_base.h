#ifndef _PROBLEM_BASE_H_
#define _PROBLEM_BASE_H_

#include <string>
#include <tuple>
#include <chrono>

using std::tuple;
using std::wstring;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;
using std::chrono::high_resolution_clock;

template<unsigned problem_number> class ProblemBase
{
    const unsigned problem_number_;
    public:
        ProblemBase() : problem_number_(problem_number)
        {
        }

        // Euler project problem number, result as a string, duration taken for calculation
        tuple<unsigned, wstring, nanoseconds> execute()
        {
            const auto before = high_resolution_clock::now();
            const auto result = execute_core();
            const auto after = high_resolution_clock::now();
            return std::make_tuple(problem_number_, result, duration_cast<nanoseconds>(after - before));
        }

        virtual wstring execute_core() = 0;
};

#define DEFINE_EXECUTE_CORE_ONLY(NUMBER) template<> using ProblemNUMBER = ProblemBase< NUMBER >; template<> wstring ProblemBase<NUMBER>::execute_core()

#endif