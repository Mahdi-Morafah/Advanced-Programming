#include"libArr.h"

libArr::libArr(long int n) {
  this-> n = n;
  arr = new long int[n];
  for(long int i{}; i < n; i++)
    arr[i] = i;
}
libArr::libArr(): libArr(0) {}

libArr::libArr(const libArr& lib) {
  n = lib.n;
  arr = new long int[n];
  for(long int i{}; i < n; i++)
    arr[i] = lib.arr[i]; 
}
long int libArr::counter(){
  for(long int i{}; i < n; i++)
    result += arr[i];
  return result;
}
  

libArr::~libArr() {
    delete[] arr;
}
