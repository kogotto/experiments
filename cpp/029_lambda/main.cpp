#include <iostream>

/* #include <string> */
#include <string_view>


#define pr(s) {std::cout << #s << " = " << (s) << std::endl;}

int main() {
    const int n = 42;
    int l = [n = n] () {
        return ++n;
    } ();
}
