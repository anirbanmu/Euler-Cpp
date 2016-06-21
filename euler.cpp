#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "problem_headers.h"

using namespace std;

int main(int, char**)
{
   vector<tuple<unsigned, string, nanoseconds>> v;
   v.emplace_back(Problem1().execute());
   v.emplace_back(Problem2().execute());
   v.emplace_back(Problem3().execute());
   v.emplace_back(Solver4().execute());
   v.emplace_back(Solver5().execute());
   v.emplace_back(Solver6().execute());
   v.emplace_back(Solver7().execute());
   sort(v.begin(), v.end(), [](const auto& a, const auto& b){ return get<0>(a) < get<0>(b); });

   // Display all results and their runtimes

   for (const auto& res : v)
   {
       cout << "[ Problem " << get<0>(res) << " ] » " << setw(9) << get<1>(res) << " » " << setw(9) << get<2>(res).count() << " ns" << endl;
   }
   return 0;
}