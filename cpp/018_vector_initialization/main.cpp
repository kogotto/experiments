#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct Foo {
    vector<string> v;
    int a;
};

void print(const Foo& f) {
    cout << "print" << endl;
    for (const auto s : f.v) {
        cout << s << endl;
    }
    cout << "a = " << f.a << endl;
}

int main() {
    Foo v{{"some", "text"}, 10};
    print(v);
}
