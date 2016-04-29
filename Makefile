CXX := clang++
CXXFLAGS := -O2 -Wall -Werror -std=c++14

# Link
euler: euler.o problems/*.o
    $(CXX) $(CXXFLAGS) $(inputs) -o $(output)

euler.o: euler.cpp
    $(CXX) $(CXXFLAGS) -c $(input) -o $(output)

# Euler runner
euler.cpp: scripts/gen_euler.py problem_headers.h
	python3 scripts/gen_euler.py problem_headers.h euler.cpp

# All headers
problem_headers.h: scripts/gen_mega_header.py problems/*.h
	python3 scripts/gen_mega_header.py problems problem_headers.h