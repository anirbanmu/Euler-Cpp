# coding: utf-8
# Just creates a meta header files that includes all others in given dir arg1 and header is generated at arg2

import glob, os, sys

header_cpp = '#ifndef _MEGA_PROB_H_\n#define _MEGA_PROB_H_\n\n'
footer_cpp = '\n#endif'

def include_header_cpp(header, rel_loc):
    return '#include "' + os.path.relpath(header, os.path.split(rel_loc)[0]) + '"\n'

def aggregate_includes_cpp(header_dir, rel_loc):
    return ''.join([include_header_cpp(f, rel_loc) for f in sorted(glob.glob(os.path.join(header_dir, '*.h')))])

header_loc = sys.argv[1]
megaheader_loc = sys.argv[2]

includes_cpp = aggregate_includes_cpp(header_loc, megaheader_loc)

with open(megaheader_loc, 'w') as mega:
    mega.write(header_cpp + includes_cpp + footer_cpp)