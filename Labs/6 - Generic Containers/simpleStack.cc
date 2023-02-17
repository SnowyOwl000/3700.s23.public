#include "simpleStack.h"

void Stack::push(const StackType &d) {

  if (count == STACK_SIZE)
    throw std::overflow_error("SimpleStack is full");

  data[count] = d;

  count++;

// data[count++] = d;
}

StackType Stack::pop(void) {

  if (!count)
    throw std::underflow_error("SimpleStack is empty");

  count--;

  return data[count];

// return data[--count];
}

StackType Stack::peek(void) {

  if (!count)
    throw std::underflow_error("SimpleStack is empty");

  return data[count-1];
}
