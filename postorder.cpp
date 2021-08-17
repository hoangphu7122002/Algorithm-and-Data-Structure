#include <iostream>
#include <stack>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(){val = 0;left = NULL;right = NULL;}
	TreeNode(int x):val(x),left(NULL),right(NULL){};
	TreeNode(int x,TreeNode* left,TreeNode* right):val(x),left(left),right(right){};
};

void postOrder_recur(TreeNode* root){
	if (root == NULL){
		return;
	}
	if (root->left != NULL)
		postOrder_recur(root->left);
	if (root->right != NULL)
		postOrder_recur(root->right);
	cout << root->val << ' ';
}

void postOrderTwoStack(TreeNode* root){
	if (root == NULL){
		return;
	}
	stack<TreeNode*> stk1;
	stack<TreeNode*> stk2;
	stk1.push(root);
	TreeNode* temp = NULL;
	while (stk1.size()){
		temp = stk1.top();
		stk1.pop();
		stk2.push(temp);
		if (temp->left != NULL){
			stk1.push(temp->left);
		}
		if (temp->right != NULL){
			stk1.push(temp->right);
		}
	}
	while (stk2.size()){
		cout << stk2.top();
		stk2.pop();
	}
}

void DFS(TreeNode* root){
	if (root == NULL){
		return;
	}
	stack<TreeNode*>stk;
	TreeNode* temp = root;
	do {
		while (temp){
			if (temp->right){
				stk.push(temp->right);
			}
			stk.push(temp);
			temp = temp->left;
		}
		temp = stk.top();
		stk.pop();
		if (temp->right && stk.size() && stk.top() == temp->right){
			stk.pop();
			stk.push(temp);
			temp = temp->right;
		}
		else {
			cout << temp->val << ' ';
			temp = NULL;
		}
	}while(stk.size());
}


int main() {
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	DFS(root);
	return 0;
}


