#include <iostream>
#include <stdexcept>
using namespace std;

#define pr(s) {cout << #s << " = " << (s) << endl;}
#define prs(s) pr(sizeof(s))

template <class T, size_t N>
class recursive_array :public recursive_array<T, N - 1> {
public:
  template <class U, class... Args>
  recursive_array(U&& v, Args... args):
    recursive_array<T, N-1>(args...), value(v) {}

  const T& operator[](size_t i) {
    if (i == N - 1) {
      return value;
    }
    return recursive_array<T, N-1>::operator[](i);
  }
private:
  T value;
};

template <class T>
class recursive_array<T, 0> {
public:
  const T& operator[](size_t i) {
    throw std::runtime_error("");
  }
};

int main() {
  cout << sizeof(recursive_array<int, 0>) << endl;
  cout << sizeof(recursive_array<int, 1>) << endl;
  cout << sizeof(recursive_array<int, 2>) << endl;
  cout << sizeof(recursive_array<int, 3>) << endl;

  recursive_array<int, 3> r{3, 2, 1};
  for (size_t i = 0; i < 3; ++i) {
    cout << r[i] << ' ';
  }
  cout << endl;
  cout << r[3] << endl;
}
