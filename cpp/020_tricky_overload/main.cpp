#include <iostream>
using namespace std;

void foo(double) { cout << "void foo(double)" << endl; }

/* template<typename T> */
/* void foo(T) { cout << "template<typename T> void foo(T)" << endl; } */

template<typename T>
void foo(T) { return foo(0.0); }

template<>
void foo(double) { cout << "template<> void foo(double)" << endl; }

int main() {
    cout << "hi" << endl;
    foo(0.0);
}
