//
// hsort.cc
// 
// Heap sort function
//
// Written 2-december-2016 by rwk
//

#include "sort.h"

void fixHeap(int h[],int nItems,int r) {
  int
    tmp,
    c;

  // pull root r out of heap
  tmp = h[r];

  while (r<nItems/2) {
    c = 2 * r + 1;
    // find larger child... must make sure right child exists before compare
    if (c < nItems - 1 && h[c+1] > h[c])
      c++;
    // stop if larger child not larger than parent
    if (h[c] <= tmp)
      break;
    // otherwise, move child up, root down
    h[r] = h[c];
    r = c;
  }

  h[r] = tmp;
}

void heapify(int h[],int nItems) {

  for (int i=nItems/2-1;i>=0;i--)
    fixHeap(h,nItems,i);
}

int extractMax(int h[],int nItems) {
  int
    tmp = h[0];  // remember largest item

  // move last item to root (maintain shape)
  h[0] = h[nItems-1];
  // restore parent-child heap property
  fixHeap(h,nItems-1,0);

  return tmp;
}

void sort(int data[],int nItems) {

  heapify(data,nItems);

  for (int i=nItems-1;i>0;i--)
    data[i] = extractMax(data,i+1);
}
