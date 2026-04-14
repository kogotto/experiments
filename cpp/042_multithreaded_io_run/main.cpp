#include <functional>
#include <iostream>
#include <thread>
#include <boost/asio.hpp>

class Printer {
public:
    Printer(boost::asio::io_context& io)
            : strand_{boost::asio::make_strand(io)}
            , timer1_{io, boost::asio::chrono::seconds{1}}
            , timer2_{io, boost::asio::chrono::seconds{1}} {
        timer1_.async_wait(boost::asio::bind_executor(
            strand_, std::bind(&Printer::print1, this)));
        timer2_.async_wait(boost::asio::bind_executor(
            strand_, std::bind(&Printer::print2, this)));
    }
    ~Printer() {
        std::cout << "Final counter is " << count_ <<
            std::endl;
    }

    void print1() {
        printImpl(timer1_, &Printer::print1, "Timer1");
    }

    void print2() {
        printImpl(timer2_, &Printer::print2, "Timer2");
    }
private:
    using Function = void (Printer::*)();
    void printImpl(boost::asio::steady_timer& timer,
            Function function,
            const char* prefix) {
        if (count_ < MAX_COUNT) {
            ++count_;
            std::cout << prefix << ": elapsed " << count_ <<
                "ticks, remain " << MAX_COUNT - count_ <<
                std::endl;
            timer.expires_at(timer.expiry() +
                    boost::asio::chrono::seconds{1});
            timer.async_wait(boost::asio::bind_executor(
                strand_, std::bind(function, this)));
        }
    }
    static constexpr int MAX_COUNT{10};
    boost::asio::strand<boost::asio::io_context::executor_type> strand_;
    boost::asio::steady_timer timer1_;
    boost::asio::steady_timer timer2_;
    int count_{0};
};

int main() {
    boost::asio::io_context io;

    std::cout << "start timer" << std::endl;
    Printer p{io};
    std::cout << "Do some payload while we wait timer" <<
        std::endl;
    std::thread t{
        [&] () {
            io.run();
            std::cout << "Second thread done" << std::endl;
        }
    };
    io.run();
    std::cout << "Main thread done" << std::endl;
    t.join();

    return 0;
}
