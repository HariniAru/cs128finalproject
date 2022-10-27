INCLUDES=-Iincludes/
CXXFLAGS=-std=c++20 -stdlib=libc++ -lc++abi -g -O0 -Wall -Wextra -Werror -pedantic $(INCLUDES)
CXX=clang++

exec: clean run_exec

tests: clean run_tests open_tests

run_exec: bin/main.out
	$<

run_tests: bin/tests.out
	- $<

open_exec: 
	./bin/main.out

open_tests:
	./bin/tests.out

clean:
	rm -f bin/*

bin/main.out: main.cpp location.cpp player.cpp application.cpp game_options.cpp navigatable_maze.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

bin/tests.out: tests/tests.cpp main.cpp location.cpp player.cpp application.cpp game_options.cpp navigatable_maze.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@


.DEFAULT_GOAL := exec
.PHONY: clean exec