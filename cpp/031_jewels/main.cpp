#include <iostream>
#include <string>
#include <unordered_set>
#include <array>

constexpr int size = 'z' - 'a' + 1;

class CharSet {
public:
    void insert(char c) {
        set[hash(c)] = true;
    }
    bool contains(char c) {
        return set[hash(c)];
    }
private:
    int hash(char c) {
        return c - 'a';
    }
    std::array<bool, size> set{};
};

int main() {
    std::string j, s;
    std::cin >> j >> s;

    CharSet set;
    for (char c : j) {
        set.insert(c);
    }

    int count = 0;
    for (char c : s) {
        count += set.contains(c);
    }

    std::cout << count << std::endl;
}
