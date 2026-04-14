#include <iostream>

#include <boost/iostreams/device/mapped_file.hpp>

#define pr(s) {std::cout << #s << " = " << (s) << std::endl;}

int main() {
    boost::iostreams::mapped_file stream(
        "input",
        boost::iostreams::mapped_file::readonly
    );

    pr(stream.const_data());
    pr(stream.size());

    return 0;
}
