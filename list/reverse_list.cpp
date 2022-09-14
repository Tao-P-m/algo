#include "list.h"

node * reverse_list(node * head){
    node * cur = head;
    node * pre = nullptr;
    while (cur != nullptr)
    {
        node * tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}