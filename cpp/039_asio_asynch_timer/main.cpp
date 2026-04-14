#include <iostream>
#include <boost/asio.hpp>

void print(const boost::system::error_code& /*e*/) {
    std::cout << "Timer expired" << std::endl;
}

int main() {
    boost::asio::io_context io;

    boost::asio::steady_timer timer{
        io, boost::asio::chrono::seconds{5}
    };

    std::cout << "start timer" << std::endl;
    timer.async_wait(&print);
    std::cout << "Do some payload while we wait timer" <<
        std::endl;

    io.run();

    std::cout << "goodbye" << std::endl;
    return 0;
}
