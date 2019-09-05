#include <iostream>

using namespace std;

struct A {
  A() : x(10) { cout << "default" << endl; }
  A(const A& other) : x(20) {cout << "copy" << endl; }

  int x;
};


int main() {
  A a = a;
  cout << a.x << endl;
}
