#include <iostream>
#include <boost/asio.hpp>

int main() {
    boost::asio::io_context io;

    boost::asio::steady_timer timer{
        io, boost::asio::chrono::seconds{5}
    };

    std::cout << "start timer" << std::endl;
    timer.wait();

    std::cout << "goodbye" << std::endl;
    return 0;
}
