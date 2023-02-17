#include "zenStack.h"

void ZenStack::push(void *p) {

  if (count*dSize >= STACK_SIZE)
    throw std::overflow_error("ZenStack is full");

  memcpy(data+count*dSize,p,dSize);

  count++;
}

void ZenStack::pop(void *p) {

  if (count == 0)
    throw std::underflow_error("ZenStack is empty");

  count--;

  memcpy(p,data+count*dSize,dSize);
}

void ZenStack::peek(void *p) {

  if (count == 0)
    throw std::underflow_error("ZenStack is empty");

  memcpy(p,data+(count-1)*dSize,dSize);
}
