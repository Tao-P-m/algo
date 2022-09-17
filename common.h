
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
using std::cout;
using std::endl;
using std::ifstream;
using std::ios;
using std::string;
using std::vector;
 
vector<string> read_file(string name = "text.txt");

int mario_all_path(int life, int lenth, int broken, vector<int> broken_id);