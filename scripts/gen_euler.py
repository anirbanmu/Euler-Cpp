# coding: utf-8
# arg1 -> mega duper header. arg2 -> final euler runner cpp

import os, sys

text = '#include <vector>\n'
text += '#include <iostream>\n'
text += '#include <algorithm>\n'

text += '\n#include "problem_headers.h"\n\n'

text += 'int main(int, char**)\n'
text += '{\n'
text += '   std::vector<tuple<unsigned, wstring, microseconds>> v;\n'

problem_header = sys.argv[1]
with open(problem_header, 'r') as h:
    for line in h:
        line = line.strip()
        if line.startswith('#include "') and line.endswith('.h"'):
            text += '   {\n'

            problem_num = line.split('/')[-1].split('.')[0]

            text += '       const auto res = Problem' + problem_num + '().execute();\n'
            text += '       v.emplace_back(res);\n'
            text += '   }\n\n'

    text += '   std::sort(v.begin(), v.end(), [](const auto& a, const auto& b){ return std::get<0>(a) < std::get<0>(b); });\n\n'

    text += '   // Display all results and their runtimes\n\n'
    text += '   for (const auto& res : v)\n'
    text += '   {\n'
    text += '       std::wcout << L"[ Problem " << std::get<0>(res) << L" ] ( •̀ω•́ )σ " << std::get<1>(res) << " ԅ(◉෴◉ԅ) in " << std::get<2>(res).count() << " microseconds" << std::endl;\n'
    text += '   }\n'

text += '   return 0;\n'
text += '}'

euler = sys.argv[2]
with open(euler, 'w') as f:
    f.write(text)