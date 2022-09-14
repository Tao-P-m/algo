#include <vector>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <iostream>
#include <unordered_map>

using std::srand;
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using std::pair;
using std::max;
using std::string;
using std::stoi;

struct TreeNode {
	int val;
	TreeNode * left;
	TreeNode * right;
	struct TreeNode(int a)
	{
		val = a;
		left = nullptr;
		right = nullptr;
	};
};

typedef struct TreeNode Tnode;

void build_tree(Tnode* &T, vector<string> & arr);
void build_tree(Tnode* &T);

void preOrderRecur(Tnode * head);
void midOrderRecur(Tnode * head);