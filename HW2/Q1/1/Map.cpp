#include"Map.h"
#include<iostream>
#include<string>
#include<iomanip>

Map::Map(int a) {
  n = a;
  row = 0;
  col = 0;
  distance = 0;
  map = new int*[n];
  for(int i{}; i < n; i++)
    map[i] = new int[n];
  
  for(int i{}; i < n; i++)
    for(int j{}; j < n; j++)
      map[i][j] = (std::rand() % 101);

  index = new int*[n];
  for(int i{}; i < n; i++)
    index[i] = new int[n];
  
  for(int i{}; i < n; i++)
    for(int j{}; j < n; j++)
      index[i][j] = 0;
  index[0][0] = 1;
}

Map::Map(const Map& m){
  n = m.n;
  map = new int*[n];
  for(int i{}; i < n; i++)
    map[i] = new int[n];
  
  for(int i{}; i < n; i++)
    for(int j{}; j < n; j++)
      map[i][j] = m.map[i][j];

  index = new int*[n];
  for(int i{}; i < n; i++)
    index[i] = new int[n];
  
  for(int i{}; i < n; i++)
    for(int j{}; j < n; j++)
      index[i][j] = m.index[i][j];
}

void Map::showMap() {
  for(int i{}; i < n; i++){
    for(int j{}; j < n; j++)
      std::cout << std::setw(4) << map[i][j];
    std::cout << std::endl;
  }
}

void Map::showRoute(){
  std::cout << "Route: " << route << std::endl;
  
  for(int i{}; i < n; i++){
    for(int j{}; j < n; j++){
      if(index[i][j] == 1)
	std::cout << std::setw(3) << "*";
      else
	std::cout << std::setw(3) << "-";
    }
    std::cout << std::endl;
  }
}

void Map::findRoute() {
  while(!((row == n-1) & (col == n-1))) {
    if((row < n-1) && (col < n-1)){
      if(std::abs((map[row][col + 1] - map[row][col])) >= std::abs((map[row+1][col] - map[row][col]))){
	distance += std::abs((map[row+1][col] - map[row][col]));
	row += 1;
	route += 'd'; 
      }
      else if(std::abs((map[row][col + 1] - map[row][col])) <= std::abs((map[row+1][col] - map[row][col]))){
	distance += std::abs((map[row][col + 1] - map[row][col]));
	col += 1;
	route += 'r';
      }
      index[row][col] = 1;
    }
    if(row == n-1){
      row = n-1;
      if(col < n-1)
	col += 1;
      index[row][col] = 1;
      route += 'r';
      distance += std::abs((map[row][col] - map[row][col-1]));
    }
    else if(col == n-1){
      col = n-1;
      if(row < n-1)
	row += 1;
      index[row][col] = 1;
      route += 'd';
      distance += std::abs((map[row][col] - map[row-1][col]));
    }
  }
  std::cout << "Distance: " << distance << std::endl; 
}

Map::~Map() {
  for(int i{}; i < n; i++)
    delete[] map[i];
  delete[] map;
  
  for(int i{}; i < n; i++)
    delete[] index[i];
  delete[] index;
}
