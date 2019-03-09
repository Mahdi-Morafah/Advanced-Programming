#include<iostream>
#include"Map.h"

int main(){
  int n{};
  std::cout << "Please Enter the size of your Map" << std::endl;
  std::cin >> n;
  Map map{n};
  map.showMap();
  map.findRoute();
  map.showRoute();

  return 0;
}
