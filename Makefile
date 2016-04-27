CXX := clang++
CXXFLAGS := -O2 -Wall -std=c++14

# All headers
problem_headers.h: scripts/gen_mega_header.py problems/*.h
	python scripts/gen_mega_header.py problems problem_headers.h

# Link
euler: euler.o
    $(CXX) $(CXXFLAGS) $(input) -o $(output)

# Compilation
euler.o: euler.cpp problem_headers.h
    $(CXX) $(CXXFLAGS) -c $(input) -o $(output)