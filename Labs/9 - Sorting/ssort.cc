//
// ssort.cc
// 
// Selection sort function
//
// Written 12-april-2001 by rwk
//

#include "sort.h"

void sort(int data[],int nItems) {
  int slot,i,tmp,max;

  //
  // start with last slot, move to the left until we reach the second slot.
  // don't have to do the first slot, since after the last n-1 items are in place,
  // the first one will also be in place, by default
  //

  for (slot=nItems-1;slot>0;slot--) {

    //
    // find the largest item in the list (except items that are already in place)
    //

    max = 0;
    for (i=1;i<=slot;i++)
      if (data[i] > data[max])
	max = i;

    //
    // swap item into place
    //

    tmp = data[max];
    data[max] = data[slot];
    data[slot] = tmp;
  }

}
