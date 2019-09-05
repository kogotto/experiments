#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::cout << "hi" << std::endl;
    std::fstream file("file");
    int n;
    file >> n;
    std::vector<int> v;


    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        v.push_back([&]{int k; file >> k; return k;}());
    }

    for (const auto& k : v) {
        std::cout << k << ' ';
    }
    std::cout << std::endl;
}
