CXX := clang++
CXXFLAGS := -O2 -Wall -std=c++14

# Link
euler: problems\*.o euler.o
    $(CXX) $(CXXFLAGS) $(input) -o $(output)

# Compilation
problems\%.o: problems\%.cpp problems\%.h
    $(CXX) $(CXXFLAGS) -c $(input) -o $(output)

euler.o: euler.cpp problem_headers.h
    $(CXX) $(CXXFLAGS) -c $(input) -o $(output)

# All headers
problem_headers.h: scripts/gen_mega_header.py problems/*.h
	python scripts/gen_mega_header.py problems problem_headers.h