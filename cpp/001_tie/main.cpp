#include <iostream>
#include <tuple>

using namespace std;

struct Foo {
        Foo() {
                cout << "Foo()\n";
        }

        Foo(Foo&&) {
                cout << "Foo(Foo&&)\n";
        }

        Foo(const Foo&) {
                cout << "Foo(const Foo&)\n";
        }

        Foo& operator=(Foo&&) {
                cout << "operator=(Foo&&)\n";
        }

        Foo& operator=(const Foo&) {
                cout << "operator=(const Foo&)\n";
        }

        ~Foo() {
                cout << "~Foo()\n";
        }
};

tuple<Foo> getFoo() {
        Foo result;
        return make_tuple(std::move(result));
}

int main() {
        Foo f;
        tie(f) = getFoo();
}
