#include "reg.h"

void process(string str, int i) {
    if( i == str.length())
    {
        cout << str << endl;
        return;
    }
    process(str, i + 1);
    char tmp = str[i];
    str[i] = 0;
    process(str, i + 1);
    str[i] = tmp;
}

void get_sub_string(string str){
    process(str , 0);
}

void swap(string & str, int i, int j){
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
}

void permutation(string str, int i, vector<string>& res){
    if(i == str.length()){
        res.push_back(str);
        return ;
    }
    for (int j = i; j < str.length(); j++){
        swap(str, i, j);
        permutation(str, i + 1, res);
        swap(str, i, j);
    }

}
void get_permutation(string str){
    vector<string> res;
    permutation(str, 0, res);
    for(auto p : res)
    {
        cout << p << endl;
    }

}