#include <iostream>

int main() {
    int n;
    std::cin >> n;

    if (n == 0) {
        return 0;
    }

    int current;
    std::cin >> current;

    std::cout << current << '\n';

    int last = current;

    for (int i = 1; i < n; ++i) {
        std::cin >> current;
        if (current != last) {
            std::cout << current << '\n';
            last = current;
        }
    }
}
