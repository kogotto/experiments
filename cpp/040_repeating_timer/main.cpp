#include <functional>
#include <iostream>
#include <boost/asio.hpp>

constexpr int MAX_COUNT = 5;

// auto prepareCallback(boost::asyo::jk)
// const auto callback = 

void print(const boost::system::error_code& e /*e*/,
        boost::asio::steady_timer* timer, int* count) {
    if (*count < MAX_COUNT - 1) {
        std::cout << "elapsed " << *count + 1 <<
            " ticks, remain " << MAX_COUNT - *count - 1 <<
            std::endl;
        ++(*count);
        timer->expires_at(timer->expiry() +
                boost::asio::chrono::seconds{1});
        timer->async_wait(
            [timer, count](const boost::system::error_code& e) {
                return print(e, timer, count);
            });
        return;
    }
    std::cout << "Timer expired" << std::endl;
}

int main() {
    boost::asio::io_context io;

    boost::asio::steady_timer timer{
        io, boost::asio::chrono::seconds{1}
    };

    std::cout << "start timer" << std::endl;
    int count = 0;
    timer.async_wait(
        [timer = &timer, count = &count](const boost::system::error_code& e) {
            return print(e, timer, count);
        });
    std::cout << "Do some payload while we wait timer" <<
        std::endl;

    io.run();

    std::cout << "count now is " << count << std::endl;
    return 0;
}
