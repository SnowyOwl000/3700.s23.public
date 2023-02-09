#ifndef STACK_H
#define STACK_H

const uint32_t
  STACK_SIZE = 16;
  
typedef int StackType;

class Stack {
 public:
  Stack() { top = 0; }
  ~Stack() = default;
  
  bool isEmpty() { return top == 0; }
  uint32_t size() { return top; }
  void clear() { top = 0; }
  
  void push(StackType d);
  StackType pop();
  StackType peek();
  
 private:
  uint32_t
    top;
  StackType
    data[STACK_SIZE];
};

#endif

