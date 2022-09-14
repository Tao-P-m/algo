#include "sort.h"

void swap(vector<int> & arr, int idx1, int idx2){
    if (idx1 >= (int)arr.size() || idx2 >= (int)arr.size() ||\
        idx1 < 0 || idx2 < 0){
        cout << "Error index ";
        cout << idx1 << " ";
        cout << idx2 << " ";
        cout << "array size is ";
        cout << arr.size() << " ";
        cout << endl;
    }
    int tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}

vector<int> build_input_nums(int max_nums, int max_range){
    srand((unsigned)time(NULL));
    
    int nums = rand() % max_nums; 

    vector<int> arr;
    for(int i = 0; i < nums;i++ ){
        arr.emplace_back(rand() % max_range);
    }
    return arr;
}