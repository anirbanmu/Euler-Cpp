#include "6.h"

using namespace std;

// https://en.wikipedia.org/wiki/Square_pyramidal_number#Derivation_of_the_summation_formula
unsigned long Solver6::sum_of_squares(std::tuple<unsigned long, unsigned long> range)
{
    auto calc_sum_of_squares = [](unsigned long n) -> unsigned long { if (n == 0){ return 0; } return n * (n + 1) * (2 * n + 1) / 6; };
    return calc_sum_of_squares(get<1>(range)) - calc_sum_of_squares(get<0>(range) - 1);
}

unsigned long Solver6::square_of_sum(std::tuple<unsigned long, unsigned long> range)
{
    // Sum of consecutive integers upto (inclusive) n is equal to n * (n + 1) / 2
    // Derivation:
    //     Sum(n) = 1 + 2 + 3 + ... + (n - 2) + (n - 1) + n
    //            = (n - (n - 1)) + (n - (n - 2)) + ... + (n - 2) + (n - 1) + n
    //            = n * n + Sum(n - 1)
    //     Sum(n) + Sum(n - 1) = n * n
    //     Sum(n) + Sum(n) - n = n * n
    //     Sum(n) = (n * n + n) / 2
    auto calc_consecutive_sum = [](unsigned long n) -> unsigned long { return (n * n + n) / 2; };
    auto const sum = calc_consecutive_sum(get<1>(range)) - calc_consecutive_sum(get<0>(range) - 1);
    return sum * sum;
}