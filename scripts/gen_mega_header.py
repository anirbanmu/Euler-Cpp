# coding: utf-8
# Just creates a meta header files that includes all others in given dir arg1 and header is generated at arg2

import glob, os, sys

header_loc = sys.argv[1]
megaheader_loc = sys.argv[2]

text = '#ifndef _MEGA_PROB_H_\n#define _MEGA_PROB_H_\n\n'
for f in sorted(glob.glob(os.path.join(header_loc, '*.h'))):
    text = text + '#include "' + os.path.relpath(f, os.path.split(megaheader_loc)[0]) + '"\n'

text = text + '\n#endif'

with open(megaheader_loc, 'w') as mega:
    mega.write(text)