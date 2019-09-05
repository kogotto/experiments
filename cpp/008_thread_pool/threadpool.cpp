#include "threadpool.h"

namespace utils {

ThreadPool::ThreadPool(size_t size) {
  for (size_t i = 0; i < size; ++i) {
    threads_.emplace_back([=] {

        });
  }
}

}
