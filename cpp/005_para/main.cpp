#include <iostream>
#include <cstdint>
#include <future>

uint32_t foo(uint32_t x) {
  if (x <= 1) {
    return 1;
  }

  return foo(x - 1) + foo(x - 2);
}

auto call(uint32_t x) {
  /* return std::async(foo, x); */
  return std::async(std::launch::async, [](auto x) { return foo(x);}, x);
  /* return foo(43); */
}

int main() {
  auto f1 = call(43);
  auto f2 = call(43);
  auto f3 = call(43);
  auto f4 = call(43);
  auto f5 = call(43);
  auto f6 = call(43);
  std::cout << f1.get() << std::endl;
  std::cout << f2.get() << std::endl;
  std::cout << f3.get() << std::endl;
  std::cout << f4.get() << std::endl;
  std::cout << f5.get() << std::endl;
  std::cout << f6.get() << std::endl;
}
