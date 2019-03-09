#ifndef UTIL_H
#define UTIL_H

#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include<vector>

bool check(const std::string&, const std::string&);
std::string cal(std::string, std::vector<std::string>, std::vector<std::string>);
void Create_Text(std::ifstream&, std::ofstream&);

#endif
