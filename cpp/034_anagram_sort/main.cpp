#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string lhs, rhs;
    std::cin >> lhs >> rhs;

    std::sort(lhs.begin(), lhs.end());
    std::sort(rhs.begin(), rhs.end());

    std::cout << (lhs == rhs);
}
