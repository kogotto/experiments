#pragma once

#include <queue>
#include <mutex>
#include <conditional_variable>

template<class T>
class ConcurentQueue {
public:
    void push(T&& elem);
    T wait_and_pop();
    bool empty() const;
private:
  std::mutex mutex_;
  std::conditional_variable conditional_variable_;
  std::queue<T> queue_;
};

template<class T>
void ConcurentQueue::push(T&& elem) {
    std::unique_lock lock(mutex_);
    queue_.push_back(std::move(elem));

    lock.unlock();
    conditional_variable_.notify_one();
}

template<class T>
T wait_and_pop() {
}
