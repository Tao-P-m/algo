#include <stdlib.h>
#include <vector>
#include <iostream>
#include <algorithm>

#include "sort/sort.h"
#include "list/list.h"
#include "tree/tree.h"
#include "fread.h"

using std::vector;
using std::cin;
using std::cout;
using std::srand;
using std::sort;

void print_arr(vector<int> arr){
    for(auto i : arr){
        cout << i << " ";
    }
    cout << endl;
}

void test_sort(){
    vector<int> q = build_input_nums(5000, 10000);
    vector<int> arr;
    arr.insert(arr.end(), q.begin(), q.end());
    vector<int> arr_cp = arr;

    // sort(arr.begin(), arr.end());
    // mergesort(arr_cp, 0, arr_cp.size() - 1);
    quicksort(arr, 0, arr.size() - 1);
    heapsort(arr_cp);

    // print_arr(merged_q);

    if (arr_cp == arr){
        cout << "PASS!" << endl;
    }else {
        cout << "\nFailed!\n" << endl;
    }
}

void test_list(){
    int max_len = 5000;
    int list_len = rand() % max_len;

    int loop_len = 0;

    node *head = build_list(list_len, loop_len);
    cout << head << endl;
    
    print_list(head);
    node* rev_rev_head = reverse_list(reverse_list(head));
    print_list(rev_rev_head);
    destory_list(rev_rev_head, list_len);
    head = nullptr;
    rev_rev_head = nullptr;
}
int main(int argc, char *argv[])
{
    Tnode * top = nullptr;
    
    vector<string> arr = read_file("D:\\work\\C\\text.txt");
    build_tree(top, arr);

    preOrderRecur(top);
    cout << endl;
    midOrderRecur(top);

    return 0;
}