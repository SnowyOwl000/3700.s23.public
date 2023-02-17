#ifndef _STACK_H
#define _STACK_H

#include <stdexcept>

const int STACK_SIZE = 10;
typedef int StackType;

class Stack {
 public:
  Stack(void) { count = 0; }
  ~Stack(void) { }

  void clear(void) { count = 0; }
  int size(void) { return count; }
  bool isEmpty(void) { return count == 0; }

  void push(const StackType &d) {

    if (count == STACK_SIZE)
      throw std::overflow_error("Stack is full");

    data[count] = d;

    count++;
  }

  StackType pop(void) {

    if (!count)
      throw std::underflow_error("Stack is empty");

    count--;

    return data[count];

  }

  StackType peek(void) {

    if (!count)
      throw std::underflow_error("Stack is empty");

    return data[count-1];
  }

 private:
  StackType
   data[STACK_SIZE];
  int
   count;
};

#endif
