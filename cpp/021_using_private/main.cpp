#include <iostream>
using namespace std;

class Foo {
    void foo() {
        cout << "Foo::foo" << endl;
    }
};

class Bar: public Foo {
    public:
        using Foo::foo;
};


int main() {
    Bar().foo();
}
