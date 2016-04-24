#ifndef _PROBLEM_BASE_H_
#define _PROBLEM_BASE_H_

#include <string>
#include <tuple>
#include <chrono>

using std::tuple;
using std::wstring;
using std::chrono::duration_cast;
using std::chrono::microseconds;
using std::chrono::high_resolution_clock;

template<typename T, unsigned problem_number> class ProblemBase
{
    const unsigned promblem_number_;
    public:
        ProblemBase() : promblem_number_(problem_number)
        {
        }

        // Euler project problem number, result as a string, duration taken for calculation
        tuple<unsigned, wstring, microseconds> execute()
        {
            const auto before = high_resolution_clock::now();
            const auto result = execute_core();
            const auto after = high_resolution_clock::now();
            return std::make_tuple(promblem_number_, result, duration_cast<microseconds>(after - before));
        }

        virtual wstring execute_core() = 0;
};

#endif