#include <iostream>
#include <type_traits>

/* template<class T, class U> */
/* void f(T& t, U& u) { */
/*   std::cout << __PRETTY_FUNCTION__ << std::endl; */
/* } */

/* template<class T> */
/* void f(int t, T u) { */
/*   std::cout << __PRETTY_FUNCTION__ << std::endl; */
/* } */

/* template<> */
/* void f<int, int>(int t, int u) { */
/*   std::cout << __PRETTY_FUNCTION__ << std::endl; */
/* } */

class C {
public:
  C() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }

  template<class T, class U = std::enable_if_t<!std::is_same<std::remove_cv_t<T>, C>::value, T> >
  C(T& t) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }

  C(const C& c) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
};

int main() {
  volatile C c;
  C c1(c);
}
