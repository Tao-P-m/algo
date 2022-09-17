#include "common.h"


int process(int i, int life, int lenth, vector<int> broken_ids){
    int res = 0;
    if (i > lenth + 1){
        return 0;
    }
    if (life <= 0){
        return 0;
    }
    if (i == lenth + 1){
        return 1;
    }

    for (auto id : broken_ids){
        if(i == id){
            life = life-1;
        }

    }
    return process(i + 1, life, lenth, broken_ids) 
            + process(i + 2, life, lenth, broken_ids) 
            + process(i + 3, life, lenth, broken_ids);
}

int mario_all_path(int life, int lenth, int broken, vector<int> broken_id)
{
    int res = process(0, life, lenth, broken_id);
    return res;
}