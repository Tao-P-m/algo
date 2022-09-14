#ifndef SORT_H
    #define SORT_H

#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using std::vector;
using std::srand;
using std::cout;
using std::endl;

vector<int> quicksort(vector<int> & q, int L ,int R);

vector<int> mergesort(vector<int> & q, int L ,int R);

void heapsort(vector<int>& arr);

void swap(vector<int> & arr, int idx1, int idx2);

vector<int> build_input_nums(int max_nums, int max_range);

#endif