//
// qsort.cc
// 
// Merge sort function
//
// Written 17-april-2001 by rwk
//


//
// normally, the sort functions take two parameters: a list of data and a
// count. Recursive sorts take a list, a start point and an end point.

void qSort(int data[],int start,int end) {
  int i,bdy,tmp;

  //
  // handle the base case (list with zero or one item)
  //

  if (start >= end)
    return;

  //
  // partition the list
  //

  bdy = start;

  for (i=start+1;i<=end;i++)
    if (data[i] < data[start]) {
      bdy++;
      tmp = data[bdy];
      data[bdy] = data[i];
      data[i] = tmp;
    }

  //
  // put pivot into place
  //

  tmp = data[start];
  data[start] = data[bdy];
  data[bdy] = tmp;

  // 
  // recursively sort both sides
  //

  qSort(data,start,bdy-1);
  qSort(data,bdy+1,end);
}



//
// this is a "wrapper" function - it takes the parameters that are given to the
// sorter (array and size), and converts them into what the real code needs 
// (array, start & end points, auxiliary array)
//

void sort(int data[],int nItems) {
  qSort(data,           // array of data
	0,              // starting point - first item in array
	nItems-1);      // ending point - last item in array
}
