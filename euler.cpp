#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

#include "problem_headers.h"

int main(int, char**)
{
   std::vector<tuple<unsigned, wstring, nanoseconds>> v;
   v.emplace_back(Problem1().execute());
   v.emplace_back(Problem2().execute());
   v.emplace_back(Problem3().execute());
   v.emplace_back(Problem4().execute());
   std::sort(v.begin(), v.end(), [](const auto& a, const auto& b){ return std::get<0>(a) < std::get<0>(b); });

   // Display all results and their runtimes

   for (const auto& res : v)
   {
       std::wcout << L"[ Problem " << std::get<0>(res) << L" ] » " << std::setw(7) << std::get<1>(res) << L" » " << std::setw(7) << std::get<2>(res).count() << L" ns" << std::endl;
   }
   return 0;
}