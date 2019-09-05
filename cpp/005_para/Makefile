.PHONY: run trun clean

all: a.out

clean:
	rm a.out

run: a.out
	./a.out

trun: a.out
	time ./a.out

a.out: main.cpp
	clang++-5.0 -std=c++17 -g -pthread main.cpp
