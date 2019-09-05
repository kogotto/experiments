#include <string>
#include <vector>
#include <iostream>

struct Foo {
  Foo(const std::string& s): s(s) {}
  std::string s;
};

const std::string& getFoo() {
  static const std::string result = "kajdfkj";
  return result;
}

int main() {
  std::string s = "adfadfasdf";
  Foo f{s};
  std::vector<Foo> v;
  v.push_back({s});
  v.push_back({getFoo()});
  std::cout << f.s;
  for (const auto& f1: v) {
    std::cout << f1.s << std::endl;
  }
}
