#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "problem_headers.h"

using namespace std;

int main(int, char**)
{
    vector<unique_ptr<ProblemInterface>> problems;
    problems.emplace_back(new Problem1);
    problems.emplace_back(new Problem2);
    problems.emplace_back(new Problem3);
    problems.emplace_back(new Solver4);
    problems.emplace_back(new Solver5);
    problems.emplace_back(new Solver6);
    problems.emplace_back(new Solver7);
    problems.emplace_back(new Solver8);

    auto results = vector<tuple<unsigned, string, nanoseconds>>(problems.size(), tuple<unsigned, string, nanoseconds>());
    transform(problems.begin(), problems.end(), results.begin(), [](auto& p){ return p->execute(); });
    sort(results.begin(), results.end(), [](const auto& a, const auto& b){ return get<0>(a) < get<0>(b); });

    // Display all results and their runtimes

    for (const auto& res : results)
    {
        cout << "[ Problem " << get<0>(res) << " ] » " << setw(11) << get<1>(res) << " » " << setw(9) << get<2>(res).count() << " ns" << endl;
    }
    return 0;
}