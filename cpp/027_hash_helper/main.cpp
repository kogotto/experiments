#include <iostream>

/* #include <string> */
#include <string_view>


namespace std {

template <typename Char>
struct hash<std::basic_string_view<Char>> {
    size_t operator()(const std::basic_string_view<Char>& sv) const {
        constexpr size_t p = 31;
        constexpr size_t m = 1e9 + 9;
        size_t result = 0;
        size_t pow = 1;
        for (auto c : sv) {
            result = (result + toInt(c) * pow) % m;
            pow = (pow * p) % m;
        }
        return result;
    }

};

} // namespace std

#define pr(s) {std::cout << #s << " = " << (s) << std::endl;}

constexpr size_t MAX_COUNT = 1e9;

size_t countIterations(size_t p, size_t m) {
    size_t pow = 1;
    const size_t startedWith = pow;
    for (size_t i = 0; i < m; ++i) {
        pow = (pow * p) % m;
        if (pow == startedWith) {
            return i + 1;
        }
    }
    return static_cast<size_t>(-1);
}

int main() {
    constexpr size_t p = 31;
    constexpr size_t m = 1e9 + 9;
    pr(p);
    pr(m);
    pr(countIterations(p, m));
}
