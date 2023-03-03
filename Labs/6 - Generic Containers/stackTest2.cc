#include <iostream>
#include "zenStack.h"

using namespace std;

int main(void) {
  int x,d;

  Stack myStack;

  cout << "Enter a number: ";
  cin >> x;

  while (x != 0) {
    d = x % 10;
    x /= 10;

    myStack.push(d);
  }


  while (!myStack.isEmpty()) {
    d = myStack.pop();
    cout << d << endl;
  }

  return 0;
}
