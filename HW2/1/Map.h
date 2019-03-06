#ifndef MAP_H
#define MAP_H

#include<iostream>
#include<string>

class Map {
 public:
  Map(int );
  Map(const Map& );
  ~Map();
  void ShowMap();
  void FindRoute();

 private:
  int n{};
  int** map{};
  int** index{}; 
  int row{};
  int col{};
  int distance{};
  std::string route{};
};

#endif
