#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>
#include <stdexcept>

using namespace std;

extern std::vector<std::pair<std::string,std::string> > sign_vector;

void generate_sign_vector(std::string word);
void sort_sign_vector();
void print(char *outfilename);
