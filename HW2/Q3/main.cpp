#include<iostream>
#include "util.h"


int main(){
  std::ifstream in{"db.txt"};
  std::ofstream out{"dbnew.txt"};

  Create_Text(in, out);
  
  return 0;
}
