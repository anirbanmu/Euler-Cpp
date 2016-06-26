# coding: utf-8
# arg1 -> location of class headers. arg2 -> final euler runner cpp

import os, sys, re, glob

header_cpp = ('#include <vector>\n'
              '#include <iostream>\n'
              '#include <algorithm>\n'
              '#include <iomanip>\n'
              '#include <thread>\n'
              '#include "problem_headers.h"\n\n'

              'using namespace std;\n\n'

              'void execute_problems(vector<unique_ptr<ProblemInterface>>& problems, vector<tuple<unsigned, string, nanoseconds>>& results, size_t start, size_t end)\n'
              '{\n'
              '    if (start >= end) return;\n'
              '    for (size_t i = start; i < end; ++i)\n'
              '    {\n'
              '        results[i] = problems[i]->execute();\n'
              '    }\n'
              '}\n\n'

              'int main(int, char**)\n'
              '{\n'
              '    const auto before = high_resolution_clock::now();\n'
              '    vector<unique_ptr<ProblemInterface>> problems;\n')

footer_cpp = ('    auto results = vector<tuple<unsigned, string, nanoseconds>>(problems.size(), tuple<unsigned, string, nanoseconds>());\n\n'

              '    vector<thread> threads;\n'
              '    const unsigned num_threads = 4;\n'
              '    const unsigned problems_per_thread = problems.size() / 4;\n'
              '    for (unsigned i = 0; i < num_threads; ++i)\n'
              '    {\n'
              '        threads.emplace_back(execute_problems, ref(problems), ref(results), i * problems_per_thread, (i + 1 == num_threads) ? problems.size() : (i + 1) * problems_per_thread);\n'
              '    }\n'
              '    for_each(threads.begin(), threads.end(), [](auto& t){ t.join(); });\n\n'

              '    sort(results.begin(), results.end(), [](const auto& a, const auto& b){ return get<0>(a) < get<0>(b); });\n\n'

              '    // Display all results and their runtimes\n\n'
              '    for (const auto& res : results)\n'
              '    {\n'
              '        cout << "[ Problem " << get<0>(res) << " ] » " << setw(11) << get<1>(res) << " » " << setw(9) << get<2>(res).count() << " ns" << endl;\n'
              '    }\n\n'

              '    const auto after = high_resolution_clock::now();\n'
              '    cout << endl << "Total execution time: " << duration_cast<nanoseconds>(after - before).count() << " ns" << endl;\n'
              '    return 0;\n'
              '}')

def get_solver_classes(header):
    solver_re = re.compile('class\s+(\w+)\s+:\s+public\s+ProblemBase<\d+>')
    with open(header, 'r') as h:
        return [match.group(1) for match in solver_re.finditer(h.read())]
    return []

def aggregate_solver_classes(header_dir):
    classes_in_each = [get_solver_classes(f) for f in glob.glob(os.path.join(header_dir, '*.h'))]
    return [c for classes in classes_in_each for c in classes]

def get_solver_creation_cpp(solver_class):
    return '    problems.emplace_back(new ' + solver_class + ');\n'

solvers_creation_cpp = ''.join([get_solver_creation_cpp(c) for c in sorted(aggregate_solver_classes(sys.argv[1]))])

euler = sys.argv[2]
with open(euler, 'w') as f:
    f.write(header_cpp + solvers_creation_cpp + '\n' + footer_cpp)