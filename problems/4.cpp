#include <iostream>
#include <vector>
#include <tuple>
#include "4.h"

using namespace std;

unsigned long pow(unsigned long b, unsigned long p)
{
    auto r = 1;
    for (auto i = 0; i < p; ++i)
    {
        r *= b;
    }
    return r;
}

bool is_palindrome(unsigned long n)
{
    const auto s = to_string(n);
    const size_t length = s.length();
    for (size_t i = 0; i < length / 2; ++i)
    {
        if (s[i] != s[length - i - 1]) return false;
    }
    return true;
}

// Traverses bottom half of multiplication table diagonal by diagonal such that a higher product
// than the current cannot be ever seen later. This means the very first palindrome we find is the
// answer.
unsigned long highest_palindrome(unsigned digits)
{
    const unsigned long limit = pow(10, digits);

    unsigned long x = limit - 1, y = limit - 1, last_diag_x = limit - 1, last_diag_y = limit - 1;
    bool from_main_diagonal = true;

    while(x != 1 || y != 1)
    {
        const auto product = x * y;
        if (is_palindrome(product)) return product;

        // Move up to smaller diagonal
        if (x - 1 == 0 || y + 1 == limit)
        {
            if (from_main_diagonal)
            {
                x = last_diag_x - 1;
                y = last_diag_y;
                from_main_diagonal = false;
            }
            else
            {
                x = last_diag_x = last_diag_x - 1;
                y = last_diag_y = last_diag_y - 1;
                from_main_diagonal = true;
            }
            continue;
        }

        x -= 1;
        y += 1;
    }

    return 0;
}

string Solver4::execute_core()
{
    return to_string(highest_palindrome(3));
}