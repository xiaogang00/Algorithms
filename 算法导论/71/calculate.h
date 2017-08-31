#include <iostream>
#include <stack>
#include <cctype>
#include <map>
#include <utility>
#include <cstdlib>
#include <string>

using namespace std;

extern map<char,int> ops;


void init_ops();
int calculate(std::string formula);



