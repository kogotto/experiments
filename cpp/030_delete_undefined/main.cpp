#include <iostream>

#define pr(s) {std::cout << #s << " = " << (s) << std::endl;}

struct Foo;

int main() {
    Foo* p;
    delete p;
}
