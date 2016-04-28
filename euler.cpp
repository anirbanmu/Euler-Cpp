#include <vector>
#include <iostream>
#include <algorithm>

#include "problem_headers.h"

int main(int, char**)
{
   std::vector<tuple<unsigned, wstring, nanoseconds>> v;
   {
       const auto res = Problem2().execute();
       v.emplace_back(res);
   }

   {
       const auto res = Problem1().execute();
       v.emplace_back(res);
   }

   std::sort(v.begin(), v.end(), [](const auto& a, const auto& b){ return std::get<0>(a) < std::get<0>(b); });

   // Display all results and their runtimes

   for (const auto& res : v)
   {
       std::wcout << L"[ Problem " << std::get<0>(res) << L" ] »	" << std::get<1>(res) << L" » " << std::get<2>(res).count() << L" ns" << std::endl;
   }
   return 0;
}