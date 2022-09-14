#include "list.h"

node * build_node(){
    int max_range = 1000;
    node * head = new node;
    head->value = rand() % max_range;
    head->next = nullptr;
    return head;
}

node * build_list(int list_len, int loop_len){
    int len = list_len;
    if(len < 1){
        return nullptr;
    }
    int max_range = 1000;
    node * head = build_node();

    node * end = head;
    while (len > 1)
    {
        node *tmp = build_node();
        end->next = tmp;
        end = tmp;
        len--;
    }

    if (loop_len > 0 && loop_len < list_len){
        node * tmp_ptr = head;
        int diff = list_len - loop_len;
        while (diff > 0)
        {
            tmp_ptr = tmp_ptr->next;
            diff--;
        }
        end->next = tmp_ptr;
    }
    return head;
}

node * has_loop(node * head){
    node * slower = head;
    node * faster = head;

    node * loop_entry = nullptr;
    bool has_loop = false;
    while (slower != nullptr && faster->next != nullptr){
        slower = slower->next;
        faster = faster->next->next;
        if (slower == faster){
            has_loop = true;
            break;
        }
    }
    if (has_loop){
        faster = head;
        while (faster != nullptr && slower != nullptr)
        {
            faster = faster->next;
            slower = slower->next;
            if(slower == faster){
                loop_entry = slower;
                break;
            }
        }
    }
    return loop_entry;
    
}

void destory_list(node * head, int len)
{
    node * ptr = head;
    int cnt = 0;
    while (ptr != nullptr && len>0)
    {
        cout << "delet node " << ++cnt << " " << endl;
        node *next = ptr->next;
        delete [] ptr;
        ptr = next;
        len--;
    }
    head = nullptr;
}

void print_list(node * head){
    node * ptr = head;

    node * end = nullptr;
    int meet_end = 0;
    if (has_loop(head) != nullptr) {
        end = has_loop(head);
    }
    while (ptr != nullptr)
    {
        cout << ptr->value << " ";
        ptr = ptr->next;
        if (end != nullptr && ptr == end){
            meet_end++;
            if(meet_end==2){
                break;
            }
        }
    }
    cout << endl;
}