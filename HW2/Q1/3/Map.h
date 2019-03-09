#ifndef MAP_H
#define MAP_H

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

class Map {
 public:
  Map(int);
  Map(const Map&);
  ~Map();
  void showMap();
  void showRoute();
  void findRoute();

 private:
  int n{};
  int** map{};
  int** index{}; 
  int row{};
  int col{};
  int temp{};
  int dist{};
  std::vector<int> distance{};
  std::string route{};
};

#endif
