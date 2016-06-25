# coding: utf-8
# arg1 -> location of class headers. arg2 -> final euler runner cpp

import os, sys, re, glob

header_cpp = ('#include <vector>\n'
              '#include <iostream>\n'
              '#include <algorithm>\n'
              '#include <iomanip>\n'
              '#include "problem_headers.h"\n\n'

              'using namespace std;\n\n'

              'int main(int, char**)\n'
              '{\n'
              '   vector<tuple<unsigned, string, nanoseconds>> v;\n')

footer_cpp = ('   sort(v.begin(), v.end(), [](const auto& a, const auto& b){ return get<0>(a) < get<0>(b); });\n\n'

              '   // Display all results and their runtimes\n\n'
              '   for (const auto& res : v)\n'
              '   {\n'
              '       cout << "[ Problem " << get<0>(res) << " ] » " << setw(11) << get<1>(res) << " » " << setw(9) << get<2>(res).count() << " ns" << endl;\n'
              '   }\n'

              '   return 0;\n'
              '}')

def get_solver_classes(header):
    solver_re = re.compile('class\s+(\w+)\s+:\s+public\s+ProblemBase<\d+>')
    with open(header, 'r') as h:
        return [match.group(1) for match in solver_re.finditer(h.read())]
    return []

def aggregate_solver_classes(header_dir):
    classes_in_each = [get_solver_classes(f) for f in glob.glob(os.path.join(header_dir, '*.h'))]
    return [c for classes in classes_in_each for c in classes]

def get_solver_cpp(solver_class):
    return '   v.emplace_back(' + solver_class + '().execute());\n'

solvers_cpp = ''.join([get_solver_cpp(c) for c in sorted(aggregate_solver_classes(sys.argv[1]))])

euler = sys.argv[2]
with open(euler, 'w') as f:
    f.write(header_cpp + solvers_cpp + footer_cpp)