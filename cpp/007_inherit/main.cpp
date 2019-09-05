#include <iostream>
using namespace std;

struct A {
  int a;
  void foo() {
    cout << this << endl;
  }
};

struct B:
  public A
{
};

struct C:
  public B,
  public A
{
};




int main() {
  C c;
  c.B::A::foo();
}
