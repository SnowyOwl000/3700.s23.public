//
// bsort.cc
// 
// Bubble sort function, with early exit
//
// Written 12-april-2001 by rwk
//

void sort(int data[],int nItems) {
  int i,tmp;
  bool changed;

  //
  // loop as long as we exchange items during a single pass
  //

  do {

    //
    // initially, no changes
    //

    changed = false;

    //
    // make a pass through the data, exchanging out-of-order items
    //
    
    for (i=0;i<nItems-1;i++)
      if (data[i] > data[i+1]) {
	tmp = data[i];             // exchange items
	data[i] = data[i+1];
	data[i+1] = tmp;
	changed = true;            // set flag, must make another pass to verify
      }

  } while (changed);
}
