#include "sort.h"

using namespace std;

int Read(int data[],int maxItems) {
  int i;
   
   for (i=0;i<maxItems;i++) {
      cin >> data[i];   // try to get data from kbd
      
      if (!cin)
      	 break;   // quit if we have run out of data
   }
   
   return i;
}
