#include "reg.h"

using std::max;
using std::min;
int first(vector<int> &arr, int L, int R);
int second(vector<int> &arr, int L, int R);
int first(vector<int> &arr, int L, int R){
    if (L == R){
        return arr[L];
    }
    int s1 = arr[L] + second(arr, L + 1, R);
    int s2 = arr[R] + second(arr, L, R - 1);

    return max(s1, s2);

}

int second(vector<int> &arr, int L, int R){
    if (L == R){
        return 0;
    }
    int s1 = first(arr, L + 1, R);
    int s2 = first(arr, L, R - 1);

    return min(s1, s2);
}


int cal_max_score(vector<int> arr){
    if (arr.size() == 1){
        return arr[0];
    }

    int s1 = first(arr, 0, arr.size() - 1);
    int s2 = second(arr, 0, arr.size() - 1);
    int score = max(s1, s2);
    return score;
}