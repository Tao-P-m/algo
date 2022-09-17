#include "reg.h"

void process(int i, string start, string end, string other) {
    if (i == 1){
        cout << "Move " << i << " From " << start << " to " << end << endl;
    } else {
        process(i - 1, start, other, end);
        cout << "Move " << i << " From " << start << " to " << end << endl;
        process(i - 1, other, end, start);
    }
}

void hanoi(int i){
    process(i , "left", "right", "mid");
}