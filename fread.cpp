
#include <sstream>

#include "fread.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::ios;
using std::string;
using std::stringstream;
using std::stoi;

vector<string> read_file(string name)
{
    ifstream ifs;
    vector<string> res;

    ifs.open(name, ios::in);
    if (!ifs.is_open())
    {
        cout << "read fail." << endl;
        return res;
    }

    string line;

    while (getline(ifs, line)) {
        stringstream ss(line);
        string str_tmp;
        while(ss >> str_tmp){ 
            res.push_back(str_tmp);
        }
    }

    return res;
}