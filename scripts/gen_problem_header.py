# coding: utf-8
# arg1 is problem number and arg2 is which dir header goes
import sys, os

pnum = sys.argv[1]
loc = os.path.join(sys.argv[2], pnum + '.h')

text  = '#ifndef _' + pnum + '_DEF_H_\n'
text += '#define _' + pnum + '_DEF_H_\n\n'

text += '#include "../problem_base.h"\n\n'

text += '// Original prompt:\n\n'

text += 'class Solver' + pnum + ' : public ProblemBase<' + pnum + '>\n'
text += '{\n'
text +=  '    public:\n'
text +=  '        string execute_core()\n'
text +=  '        {\n'
text +=  '        }\n'
text +=  '\n'
text +=  '        ~Solver' + pnum '()\n'
text +=  '        {\n'
text +=  '        }\n'
text +=  '};\n\n'

text +=  '#endif'

with open(loc, 'w') as f:
    f.write(text)