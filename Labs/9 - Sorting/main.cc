#include "sort.h"

const int MAX_ITEMS = 100000;

int main(void) {
   int data[MAX_ITEMS],nItems;
   
   nItems = Read(data,MAX_ITEMS);
   
   sort(data,nItems);
   
   Print(data,nItems);
}
