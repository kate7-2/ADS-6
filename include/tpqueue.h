// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <list>
#include <stdexcept>

template<typename T>
class TPQueue {
 private:
  std::list<T> data;
  typename std::list<T>::iterator findPosition(const T& value) {
    auto current = data.begin();
    while (current != data.end() && current->prior >= value.prior) {
      ++current;
    }
    return current;
  }

 public:
  TPQueue() = default;
  ~TPQueue() = default;
  void push(const T& value);
  T pop();
  bool empty() const;
  const T& top() const;
  size_t count() const;
};

template<typename T>
void TPQueue<T>::push(const T& value) {
  auto pos = findPosition(value);
  data.insert(pos, value);
}

template<typename T>
T TPQueue<T>::pop() {
  if (empty()) {
    throw std::out_of_range("Queue is empty");
  }
  T result = data.front();
  data.pop_front();
  return result;
}

template<typename T>
bool TPQueue<T>::empty() const {
  return data.empty();
}

template<typename T>
const T& TPQueue<T>::top() const {
  if (empty()) {
    throw std::out_of_range("Queue is empty");
  }
  return data.front();
}

template<typename T>
size_t TPQueue<T>::count() const {
  return data.size();
}

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
