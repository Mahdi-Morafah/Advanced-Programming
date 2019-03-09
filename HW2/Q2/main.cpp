#include<iostream>
#include<vector>
#include<functional>
#include<ctime>
#include"libArr.h"
#include"libVec.h"

template <typename callable>
double RunTime(callable func){
  std::clock_t start{};
  double duration{};
  start = std::clock();
  func();
  duration = 1000 * (std::clock() - start)/(double)CLOCKS_PER_SEC;
  return duration;
}

int main(){
  libArr libarr{1000000};
  long int (libArr::*count1)(){&libArr::counter};  // pointer to member function of class libArr

  libVec libvec{1000000};
  long int (libVec::*count2)(){&libVec::counter};
  
  std::cout << "libArr Run Time: " << RunTime(std::bind(count1,libarr)) << " ms"  << std::endl;
  std::cout << "libVec Run Time: " << RunTime(std::bind(count2,libvec)) << " ms"  << std::endl;
  return 0;
}

// comments for my self
/*
//using std::function<int()> ptr_to_mem;
// You can use this as an alternative way of passing pointer to member function to another function
//ptr_to_mem ptr_to_libVec = std::bind(count2,&two); // using the type defined

//double (*temp)(int){&f}; // pointer to a simple function 
//(one.*count)(); // calling or utilizing pointer to member function 
 */
