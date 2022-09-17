#include "reg.h"



void process(int i, vector<int> arr){
    if (i == arr.size() - 1)
    {
        cout << arr[i] << " ";
        return;
    }
    process(i + 1, arr);
    cout << arr[i] << " ";
}
void reverse_stack(vector<int> arr){
    process(0, arr);
}