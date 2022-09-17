#include<string>
#include<vector>
#include<iostream>

using std::vector;
using std::string;

using std::cout;
using std::endl;

void get_input_string(vector<string>& vec)
{
    cout << "Please input :" << endl;
    string str;
    while (getline(cin, str)) {
        vec.emplace_back(str);
    }
}