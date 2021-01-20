// Copyright 2020 Ryzhova
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_
#include <iostream>

template<class Stack>
class MyStack {
 private:
  int count = 0;
  int size;
  Stack* stack;

 public:
  explicit MyStack(int size) {
    this->size = size;
    stack = new Stack[size];
  }

  MyStack(const MyStack &stack) {
    count = stack.count;
    size = stack.size;
    stack = new Stack[size];
    for (int i = 0; i < size; i++) {
      stack[i] = stack.stack[i];
    }
  }

  ~MyStack() {
    delete[] stack;
    size = 0;
  }

  Stack get() const {
    if (!isEmpty())
      return stack[count - 1];
  }

  Stack pop() {
    if (!count)
      return 0;
    count--;
    return stack[count];
  }

  void push(Stack value) {
    if (!isFull()) {
      stack[count] = value;
      count++;
    }
  }

  bool isFull() const {
    return size == count;
  }

  bool isEmpty() const {
    return count == 0;
  }
};

#endif  // INCLUDE_MYSTACK_H_
