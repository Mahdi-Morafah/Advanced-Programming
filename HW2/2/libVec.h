#ifndef LIBVEC_H
#define LIBVEC_H

#include<vector>

class libVec {
 public:
  libVec(long int);
  libVec(const libVec&);
  long int counter();
  libVec();
  ~libVec();
  
 private:
  long int n{};
  std::vector<long int> vec{};
  long int count{};
};
#endif
