#include <stdexcept>
#include "stack.h"

void Stack::push(StackType d) {
  
  if (top == STACK_SIZE)
    throw std::overflow_error("Stack is full");
    
  data[top] = d;
  
  top++;
}

StackType Stack::pop() {

  if (top == 0)
    throw std::underflow_error("Stack is empty");
    
  top--;
  
  return data[top];
}

StackType Stack::peek() {

  if (top == 0)
    throw std::underflow_error("Stack is empty");
    
  return data[top-1];
}

