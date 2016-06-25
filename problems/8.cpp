#include <iostream>
#include <cstdlib>
#include <vector>

#include "8.h"

using namespace std;

unsigned long find_product(const vector<unsigned>& numbers, unsigned long accumulated, size_t begin_index /* inclusive */, size_t end_index /* exclusive */)
{
    if (begin_index == end_index)
    {
        return accumulated;
    }
    return find_product(numbers, accumulated * numbers[begin_index], begin_index + 1, end_index);
}

vector<unsigned> extract_digits(string number)
{
    vector<unsigned> digits;

    auto scratch = string("0");
    for (const auto digit : number)
    {
        scratch[0] = digit;
        digits.emplace_back(stoi(scratch));
    }

    return digits;
}

unsigned long find_max_product(string number, unsigned consecutive_digits)
{
    const vector<unsigned> digits = extract_digits(number);

    unsigned long max_product = 0;
    for (size_t i = 0; i + consecutive_digits <= digits.size(); ++i)
    {
        max_product = max(max_product, find_product(digits, 1, i, i + consecutive_digits));
    }

    return max_product;
}