#include <iostream>
#include "stack.h"

using namespace std;

int main() {
  Stack
    s;
  int
    n = 12345,
    d;
    
  while (n != 0) {
    d = n % 10;
    n /= 10;
    
    //cout << d << endl;
    s.push(d);
  }
  
  while (!s.isEmpty()) {
    d = s.pop();
    
    cout << d << endl;
  }

  return 0;
}

