#include <vector>
#include <stdlib.h>

#include "sort.h"

vector<int> partition(vector<int> & arr, int L, int R){
    int key = rand() % (R - L) + L;
    int less = L - 1;
    int more = R;
    int i = L;
    swap(arr, key, R);
    while (i < more) {
        if(arr[i] < arr[R]){
            less++;
            swap(arr, i, less);
            i++;
        }else if(arr[i] == arr[R]){
            i++;
        }else{
            more--;
            swap(arr, i, more);
        }
    }
    swap(arr, R, more);
    vector<int> range;
    range.emplace_back(less +1);
    range.emplace_back(more);

    return range;
}
vector<int> quicksort(vector<int> & q, int L ,int R) {
    if(L < R) {
        vector<int> range = partition(q, L, R);
        quicksort(q, L , range[0] - 1);
        quicksort(q, range[1] + 1, R);
    }
    return q;
}