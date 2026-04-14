#include <functional>
#include <iostream>
#include <boost/asio.hpp>

constexpr int MAX_COUNT = 5;

class Printer {
public:
    Printer(boost::asio::io_context& io)
        : timer_{io, boost::asio::chrono::seconds{1}} {
        timer_.async_wait(std::bind(&Printer::print, this));
    }
    ~Printer() {
        std::cout << "Timer expired. Final count is " << count_ << std::endl;
    }
    void print() {
        if (count_ < MAX_COUNT - 1) {
            std::cout << "elapsed " << count_ + 1 <<
                " ticks, remain " << MAX_COUNT - count_ - 1 <<
                std::endl;
            ++count_;
            timer_.expires_at(timer_.expiry() +
                    boost::asio::chrono::seconds{1});
            timer_.async_wait(std::bind(&Printer::print, this));
        }
    }
private:
    static constexpr int MAX_COUNT = 5;
    boost::asio::steady_timer timer_;
    int count_{0};
};

int main() {
    boost::asio::io_context io;

    std::cout << "start timer" << std::endl;
    Printer p{io};
    std::cout << "Do some payload while we wait timer" <<
        std::endl;
    io.run();

    return 0;
}
