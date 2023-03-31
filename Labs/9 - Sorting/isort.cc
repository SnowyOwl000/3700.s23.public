//
// isort.cc
// 
// Insertion sort function
//
// Written 12-april-2001 by rwk
//

void sort(int data[],int nItems) {
  int split,i,tmp;

  //
  // start with split between first two items, walk split over to the far right
  //

  for (split=1;split<nItems;split++) {

    //
    // pull item out of list
    //

    tmp = data[split];

    //
    // slide larger items one slot to the right
    //

    for (i=split-1;i>=0 && data[i]>tmp;i--)
      data[i+1] = data[i];

    //
    // place item in gap left after sliding
    //

    data[i+1] = tmp;
  }
}
