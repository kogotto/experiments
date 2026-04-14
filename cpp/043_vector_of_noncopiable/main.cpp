#include <iostream>
#include <vector>
#include <boost/asio.hpp>

struct NonCopyable {
    NonCopyable() = default;
    NonCopyable(const NonCopyable&) = delete;
};

int main() {
    std::vector<NonCopyable> v;
    v.emplace_back();
    std::cout << "about to return" << std::endl;
    return 0;
}
