#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <thread>
#include "problem_headers.h"

using namespace std;

void execute_problems(vector<unique_ptr<ProblemInterface>>& problems, vector<tuple<unsigned, string, nanoseconds>>& results, size_t start, size_t end)
{
    if (start >= end) return;
    for (size_t i = start; i < end; ++i)
    {
        results[i] = problems[i]->execute();
    }
}

int main(int, char**)
{
    const auto before = high_resolution_clock::now();
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

    vector<thread> threads;
    const unsigned num_threads = 4;
    const unsigned problems_per_thread = problems.size() / 4;
    for (unsigned i = 0; i < num_threads; ++i)
    {
        threads.emplace_back(execute_problems, ref(problems), ref(results), i * problems_per_thread, (i + 1 == num_threads) ? problems.size() : (i + 1) * problems_per_thread);
    }
    for_each(threads.begin(), threads.end(), [](auto& t){ t.join(); });

    sort(results.begin(), results.end(), [](const auto& a, const auto& b){ return get<0>(a) < get<0>(b); });

    // Display all results and their runtimes

    for (const auto& res : results)
    {
        cout << "[ Problem " << get<0>(res) << " ] » " << setw(11) << get<1>(res) << " » " << setw(9) << get<2>(res).count() << " ns" << endl;
    }

    const auto after = high_resolution_clock::now();
    cout << endl << "Total execution time: " << duration_cast<nanoseconds>(after - before).count() << " ns" << endl;
    return 0;
}