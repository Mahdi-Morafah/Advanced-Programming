#include<iostream>
#include"Map.h"

int main(){
  int n{};
  std::cout << "Please Enter the size of your Map" << std::endl;
  std::cin >> n;
  Map ma{n};
  ma.ShowMap();
  ma.FindRoute();
  ma.ShowMap();

  return 0;
}
