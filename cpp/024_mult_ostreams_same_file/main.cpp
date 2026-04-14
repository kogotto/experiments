#include <iostream>
#include <fstream>

int main() {
    const char* filename = "filename.txt";
    std::ofstream stream1(filename);
    if (!stream1.is_open()) {
        std::cout << "Can not open file " << filename <<
            " for the FIRST time" << std::endl;
    }

    std::ofstream stream2(filename);
    if (!stream2.is_open()) {
        std::cout << "Can not open file " << filename <<
            " for the SECOND time" << std::endl;
    }

    stream1 << "Hi, write from stream1" << '\n';
    stream2 << "Hello, just put here some from stream2" << '\n';
}
