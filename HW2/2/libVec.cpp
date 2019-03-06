#include"libVec.h"

libVec::libVec(long int n) {
  this-> n = n;
  for(long int i{}; i < n; i++)
    vec.push_back(i);
}

libVec::libVec(const libVec& lib) {
  n = lib.n;
  vec = lib.vec;
}

libVec::libVec() = default;

long int libVec::counter() {
  for(long int i{}; i < n; i++)
    count += vec[i];
  return count;
}

libVec::~libVec() = default; 
