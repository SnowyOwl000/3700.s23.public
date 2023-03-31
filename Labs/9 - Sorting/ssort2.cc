#include <iostream>
using namespace std;

int findMaxLoc(int data[],int nItems) {
  int m=0,i;
  
  for (i=1;i<=nItems;i++)
    if (data[i] > data[m])
       m = i;
       
  return m;
}
 
void swap(int &a,int &b) {
  int tmp;
  
  tmp = a;
  a = b;
  b = tmp;
} 
 
void sort(int data[],int nItems) {
  int s,m;
  
  for (s=nItems-1;s>0;s--) {
    m = findMaxLoc(data,s);
    
    swap(data[m],data[s]);
  }
  
}
