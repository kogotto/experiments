#include <iostream>
using namespace std;

struct FooTag{};
struct BarTag{};

class Foo {
    public:
        void foo(FooTag) {
            cout << "foo()" << endl;
        }
};

class Bar: public Foo {
    public:
        void foo(BarTag) {
            cout << "Bar::foo()" << endl;
        }

        void bar() {
            foo(FooTag{});
        }
};

int main() {
    Bar b;
    b.bar();
}
