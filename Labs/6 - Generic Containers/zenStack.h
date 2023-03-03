#ifndef _ZENSTACK_H
#define _ZENSTACK_H

#include <cstring>
#include <cstdint>
#include <stdexcept>

using namespace std;

const int STACK_SIZE = 1024;

class ZenStack {
 public:
  ZenStack(uint32_t s) { count = 0; dSize = s; }
  ~ZenStack(void) { }

  void clear(void) { count = 0; }
  uint32_t size(void) { return count; }
  bool isEmpty(void) { return count == 0; }

  void push(void *);
  void pop(void *);
  void peek(void *);

 private:
  uint8_t
    data[STACK_SIZE];
  uint32_t
    count,
    dSize;
};

#endif
