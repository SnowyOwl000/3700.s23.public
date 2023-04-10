//
// msort.cc
// 
// Merge sort function
//
// Written 12-april-2001 by rwk
//


//
// normally, the sort functions take two parameters: a list of data and a
// count. Recursive sorts take a list, a start point and an end point.

void mSort(int data[],int start,int end,int aux[]) {
  int mid,L,R,k;

  //
  // handle the base case (list with one item)
  //

  if (start == end)
    return;

  //
  // split the list... left side goes from start to mid, right side goes from
  // mid+1 to end
  //

  mid = (start + end) / 2;

  //
  // recursively sort both sides
  //

  mSort(data,start,mid,aux);
  mSort(data,mid+1,end,aux);

  //
  // merge the lists
  //

  L = k = start;
  R = mid + 1;

  while (L <= mid && R <= end)
    if (data[R] < data[L])
      aux[k++] = data[R++];
    else
      aux[k++] = data[L++];

  while (L <= mid)
    aux[k++] = data[L++];

  while (R <= end)
    aux[k++] = data[R++];

  for (k=start;k<=end;k++)
    data[k] = aux[k];
}



//
// this is a "wrapper" function - it takes the parameters that are given to the
// sorter (array and size), and converts them into what the real code needs 
// (array, start & end points, auxiliary array)
//

void sort(int data[],int nItems) {
  int *aux;

  aux = new int[nItems];    // need auxiliary array

  mSort(data,           // array of data
	0,              // starting point - first item in array
	nItems-1,       // ending point - last item in array
	aux);           // auxiliary array

  delete aux;
}
