#include <iostream>
using namespace std;

template<typename... Args>
bool all(Args... args) {
    return (... && args);
}

template<typename... Args>
bool any(Args... args) {
    return (... || args);
}

template<typename... Args>
auto rightComa(Args... args) {
    return (args , ...);
}

template<typename... Args>
auto leftComa(Args... args) {
    return (... , args);
}

#define pr(s) { cout << #s << " = " << boolalpha << (s) << endl; }

int main() {
    pr(all(true))
    pr(all(false))

    pr(all(true, true))
    pr(all(true, false))
    pr(all(false, true))
    pr(all(false, false))

    pr(all(true, true, true))
    pr(all(false, true, true))
    pr(all(true, false, true))
    pr(all(true, true, false))
    pr(all(true, false, false))
    pr(all(false, false, true))
    pr(all(false, true, false))
    pr(all(false, false, false))

    pr(any(true))
    pr(any(false))

    pr(any(true, true))
    pr(any(true, false))
    pr(any(false, true))
    pr(any(false, false))

    pr(any(true, true, true))
    pr(any(false, true, true))
    pr(any(true, false, true))
    pr(any(true, true, false))
    pr(any(true, false, false))
    pr(any(false, false, true))
    pr(any(false, true, false))
    pr(any(false, false, false))

    pr(rightComa(1))
    pr(rightComa(1, 2))
    pr(rightComa(1, 2, 3))

    pr(leftComa(1))
    pr(leftComa(1, 2))
    pr(leftComa(1, 2, 3))
}
