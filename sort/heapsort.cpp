#include <vector>
#include <stdlib.h>

#include "sort.h"
using std::vector;
using std::srand;
using std::cout;

void heapinsert(vector<int> & arr, int idx){
    while (arr[idx] > arr[(idx - 1) / 2]){
        swap(arr, idx, (idx - 1) / 2);
        idx = (idx - 1) / 2;
    }
}


void heapify(vector<int> & arr, int idx, int heapsize){
    int left = 2*idx + 1;

    while(left < heapsize) {
        int largest = left;
        if (left + 1 < heapsize && arr[left] < arr[left + 1]){
            largest = left + 1;
        }
        if (arr[idx] > arr[largest]){
            largest = idx;
        }
        if (largest == idx) {
            break;
        }
        swap(arr, largest, idx);
        idx = largest;
        left = idx * 2 + 1;
    }
}

void heapsort(vector<int>& arr){
    for (int i = 0; i < arr.size(); i++){
        heapinsert(arr, i);
    }
    swap(arr, 0, arr.size() - 1);
    int heapsize = arr.size() - 1;
    while (heapsize > 0)
    {
        heapify(arr, 0, heapsize);
        heapsize--;
        swap(arr, 0 , heapsize);
        
    }
}