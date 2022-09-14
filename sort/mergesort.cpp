#include <vector>
#include <stdlib.h>

#include "sort.h"
using std::vector;
using std::srand;
using std::cout;


void merge(vector<int > & arr, int L, int R){
    vector<int> helper;

    int mid = (R + L) / 2;

    int left = L;
    int right = mid + 1;
    while (left <= mid && right <= R) {
        if (arr[left] < arr[right]) {
            helper.emplace_back(arr[left]);
            left++;
        } else {
            helper.emplace_back(arr[right]);
            right++;
        }
    }
    if(left <= mid){
        helper.insert(helper.end(), arr.begin() + left, arr.begin() + mid + 1);
    }
    if(right <= R){
        helper.insert(helper.end(), arr.begin() + right, arr.begin() + R + 1);
    }
    
    for(int i = L; i<=R;i++){
        arr[i] = helper[i - L];
    }
}
vector<int> mergesort(vector<int> & arr, int L ,int R) {
    int mid = (L + R) / 2;
    if (L < R) {
        mergesort(arr, L, mid);
        mergesort(arr, mid + 1, R);
        merge(arr, L, R);
    }
    
    return arr;
}