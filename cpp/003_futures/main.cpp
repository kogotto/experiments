#include <future>
#include <iostream>

using namespace std;

int main() {
  std::future<int> f = std::async(std::launch::async, [] { return 666; });
  cout << f.valid() << endl;
  cout << f.get() << endl;
  cout << f.valid() << endl;
  cout << f.get() << endl;
}
