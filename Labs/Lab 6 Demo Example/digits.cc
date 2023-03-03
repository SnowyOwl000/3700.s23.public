#include <iostream>
#include <stack.h>

using namespace std;

int main() {
  int
    n,d;
  Stack<int>
    myStack;
    
  cin >> n;
  
  while (n != 0) {
    d = n % 10;
    n /= 10;
    
    myStack.push(d);
  }
  
  while (!myStack.isEmpty()) {
    d = myStack.pop();
    
    cout << d << endl;
  }
  
  return 0;
}

