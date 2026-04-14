#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

using Map = std::unordered_map<char, int>;

Map toMap(const std::string& str) {
    Map result;
    for (auto c : str) {
        ++result[c];
    }
    return result;
}

int main() {
    std::string lhs, rhs;
    std::cin >> lhs >> rhs;

    const auto lhsMap = toMap(lhs);
    const auto rhsMap = toMap(rhs);

    std::cout << (lhsMap == rhsMap);
}
