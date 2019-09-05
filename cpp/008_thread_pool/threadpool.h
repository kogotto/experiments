#pragma once

#include <thread>
#include <vector>

namespace utils {

class ThreadPool {
public:
  ThreadPool(size_t size);
private:
  std::vector<std::thread> threads_;
};

}
