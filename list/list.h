#include <stdlib.h>
#include <time.h>
#include <iostream>

using std::srand;
using std::cout;
using std::endl;


struct Node
{
    int value;
    struct Node *next;
};

typedef struct Node node;

node * build_node();

node * build_list(int lenth, int loop_len = 0);

void print_list(node * head);

void destory_list(node * head, int len);

node * has_loop(node * head);

node * reverse_list(node * head);