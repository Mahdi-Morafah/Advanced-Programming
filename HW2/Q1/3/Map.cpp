#include"Map.h"
#include<iostream>
#include<string>
#include<iomanip>

Map::Map(int a) {
  n = a;
  row = 0;
  col = 0;
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

  for(int i{}; i < n-1; i++)
    route += "rd";
  
  std::sort(route.begin(), route.end());
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
    std::cout << std::setw(4); 
    for(int j{}; j < n; j++)
      std::cout << std::setw(4) << map[i][j];
    std::cout << std::endl;
  }
  // for showing all the meseaured distances use the following code
  /*
  if( distance.size() != 0){
  for(size_t i{}; i < distance.size(); i++)
    std::cout << distance[i] << std::endl;
  }
  */
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
  do{
    row = col = 0;
    dist = 0;
   
    for(int i{}; i < n; i++)
      for(int j{}; j < n; j++)
	index[i][j] = 0;
    index[0][0] = 1;
  
    for(size_t i{}; i < route.length(); i++){
      if(route[i] == 'r'){
	temp = std::abs(map[row][col+1] - map[row][col]);
	col += 1;
	index[row][col] = 1;
	dist += temp;
      }
      else if(route[i] == 'd'){
       	temp = std::abs(map[row + 1][col] - map[row][col]);
	row += 1;
	index[row][col] = 1;
	dist += temp;
      }
    }
    distance.push_back(dist);

  }while(std::next_permutation(route.begin(), route.end()));

  std::sort(distance.begin(), distance.end());
  std::cout << "The Minimum Distance is: " << distance[0] << std::endl;
}

Map::~Map() {
  
  for(int i{}; i < n; i++)
    delete[] map[i];
  delete[] map;
  
  for(int i{}; i < n; i++)
    delete[] index[i];
  delete[] index;
}
  
