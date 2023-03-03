#ifndef _SIMPLESTACK_H
#define _SIMPLESTACK_H

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

  void push(const StackType &);
  StackType pop(void);
  StackType peek(void);

 private:
  StackType
   data[STACK_SIZE];
  int
   count;
};

#endif
