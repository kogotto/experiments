#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;


int main() {
  array<int, 4> v = {{1, 2, 3, 4}};

  const int summ = [&v](){
    int summ = 0;
    std::for_each(v.begin(), v.end(), [&summ](const auto e){
        summ += e;
        });
    return summ;
  }();
  cout << summ << endl;
}
