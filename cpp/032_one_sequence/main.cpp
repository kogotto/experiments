#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int maxLen = 0;
    int currentLen = 0;

    for (int i = 0; i < n; ++i) {
        int c;
        std::cin >> c;

        if (c == 1) {
            ++currentLen;
            if (currentLen > maxLen) {
                maxLen = currentLen;
            }
        } else {
            currentLen = 0;
        }
    }

    std::cout << maxLen << std::endl;
}
