#include <iostream>

using namespace std;

class Foo {
    public:
        void foo() {
            cout << "Foo::foo()" << endl;
        }
};

class Bar : public Foo {
    public:
        void foo() {
            cout << "Bar::foo()" << endl;
        }
};

class Baz : public Foo {
    public:
        void foo() {
            cout << "Baz::foo()" << endl;
        }
};

int main() {
    Baz x;
    Bar y;

    (true ? x: y).foo();
    (false ? x: y).foo();
    /* (true ? y: x).foo(); */
    /* (false ? y: x).foo(); */
}
