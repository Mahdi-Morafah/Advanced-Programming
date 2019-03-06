#include<iostream>
#include<vector>
#include<functional>
#include<ctime>
#include"libArr.h"
#include"libVec.h"

//using std::function<int()> ptr_to_mem; //
/*
void integ(double (*f)(int a), int a){
  std::cout << f(a) << std::endl;
}
double f(int a){
  return a*a;
}

template <typename callable>
//template <typename object>
void run(callable f){
  
  std::cout << "I am Here" << std::endl;
  std::cout << f << std::endl;
}
*/

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
  std::cout << "Hello World" << std::endl;
  //integ(&f,2);
  //double (*temp)(int){&f};
  //integ(f,3);
  libArr one{1000000};
  long int (libArr::*count1)(){&libArr::counter};
  // pointer to member function of class libArr

  libVec two{1000000};
  long int (libVec::*count2)(){&libVec::counter};
  std::cout << "libArr Run Time: " << RunTime(std::bind(count1,one)) << " ms"  << std::endl;

    std::cout << "libVec Run Time: " << RunTime(std::bind(count2,two)) << " ms"  << std::endl;
    
  /*ptr_to_mem ptr_to_libVec = std::bind(count2,&two);
    std::cout << RunTime(ptr_to_libVec) << std::endl;*/
  
  //run((one.*count)());
  
  return 0;
}
