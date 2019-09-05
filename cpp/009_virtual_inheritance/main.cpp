#include <iostream>
using namespace std;

struct A {
  A(int i = 10) { cout << "A(" << i << ")" << endl; }
  void* a;
};

struct B: virtual A {
  B() : A(0) { cout << "B()" << endl; }
  void* b;
};

struct C: virtual A {
  C() : A(1) { cout << "C()" << endl; }
  void* c;
};

struct D: B, C {
  D()  { cout << "D()" << endl; }
  void* d;
};

#define pr(s) {cout << #s << " = " << (s) << endl;}
#define prs(s) pr(sizeof(s))

int main() {
  /* A a; */
  /* cout << "===" << endl; */
  B b;
  cout << "===" << endl;
  C c;
  cout << "===" << endl;
  D d;
  /* prs(A); */
  /* prs(B); */
  /* prs(C); */
  /* prs(D); */
}
