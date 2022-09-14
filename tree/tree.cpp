#include "tree.h"


Tnode * build_tree_node(int val) {

    Tnode * node = new Tnode(val);
    
    return node;
}

void build_tree(Tnode* &T, vector<string> & arr){
    if (arr.empty()){
        T = NULL;
        return ;
    }
    auto ch = arr.front();
    arr.erase(arr.begin());
    if(*ch.c_str() == '#') {
        T = NULL; 
    } else { 
        T = new Tnode(stoi(ch)); 
        build_tree(T->left, arr); 
        build_tree(T->right, arr);
    }
}

void build_tree(Tnode* &T){ 
    char ch = getchar();
    getchar();
    if(ch == '#') {
        T = NULL;
        cout << "branch 1 " << ch << endl;

    } else {
        cout << "branch 2 " << ch << endl;
        T = new Tnode(ch); 
        build_tree(T->left); 
        build_tree(T->right);
    }
}

void preOrderRecur(Tnode * head){
	if (head == nullptr)
		return;
	cout << head->val << endl;
    preOrderRecur(head->left);
    preOrderRecur(head->right);
}

void midOrderRecur(Tnode* head) {
	if (head == nullptr)
		return;
    midOrderRecur(head->left);
    cout << head->val << endl;
    midOrderRecur(head->right);
}

void posOrderRecur(Tnode* head) {
	if (head == nullptr)
		return;
    posOrderRecur(head->left);
    posOrderRecur(head->right);
	cout << head->val << endl;

}

void preOrder(Tnode* head) { 
	if (head == nullptr) {
		return;
	}
	vector<Tnode*> stack;
	stack.push_back(head);
	while (!stack.empty())
	{
		Tnode* cur = stack.back();
		stack.pop_back();
		if (cur->right != nullptr) {
			stack.push_back(cur->right);
		}
		if (cur->left != nullptr) {
			stack.push_back(cur->left);
		}
		cout << cur->val << " ";
	}
	cout << endl;
}

void posOrder(Tnode* head) {
	if (head == nullptr)
		return;
	std::vector<Tnode*> stack1;
	std::vector<Tnode*> stack2;
	stack1.push_back(head);
	while (!stack1.empty())
	{	
		Tnode* cur = stack1.back();
		stack1.pop_back();
		if (cur->left != nullptr) {
			stack1.push_back(cur->left);
		}
		if (cur->right != nullptr) {
			stack1.push_back(cur->right);
		}
		stack2.push_back(cur);
	}
	for (auto it = stack2.rbegin(); it != stack2.rend(); it++) {
		cout << (*it)->val << endl;
	}
}

void midOrder(Tnode* head) { 
	if (head != nullptr) {
		std::vector<Tnode*> stack;
		while (!stack.empty() || head != nullptr) {
			if (head != nullptr) {
				stack.push_back(head);
				head = head->left;
			}
			else {
				head = stack.back();
				stack.pop_back();
				cout << head->val << " ";
				head = head->right;
			}
		}
		cout << endl;
	}
}

void BFS(Tnode* head) {
	if (head == nullptr)
		return;
	vector<Tnode* > queue;
	queue.push_back(head);
	while (!queue.empty())
	{
		Tnode* cur = queue.front();
		cout << cur->val << " ";
		if (cur->left != nullptr)
			queue.push_back(cur->left);
		if (cur->right != nullptr)
			queue.push_back(cur->right);
		queue.erase(queue.begin());
	}
}

void find_max_width(Tnode* head) {
	if (head == nullptr)
		return;
	vector<Tnode* > queue;
	unordered_map<Tnode*, int> map;

	queue.push_back(head);
	map.insert(pair<Tnode*, int>(head, 1));
	int curlevel = 1;
	int LevelNodeNum = 0;
	int max_width = 0;
	while(!queue.empty()) {
		Tnode* cur = queue.front();
		int nodelevel = map.find(cur)->second;
		if (nodelevel == curlevel) {
			LevelNodeNum++;
		}
		else {
			max_width = max(max_width, LevelNodeNum);
			curlevel = nodelevel;
			LevelNodeNum = 1;
		}
		if (cur->left != nullptr) {
			queue.push_back(cur->left);
			map.insert(pair<Tnode*, int>(cur->left, nodelevel + 1));
		}
		if (cur->right != nullptr) {
			queue.push_back(cur->right);
			map.insert(pair<Tnode*, int>(cur->right, nodelevel + 1));
		}
		queue.erase(queue.begin());
	}
	cout << max_width << endl;
}