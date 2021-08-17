#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode():data(0),left(NULL),right(NULL){};
    TreeNode(int x):data(x),left(NULL),right(NULL){};
    TreeNode(int x,TreeNode* left,TreeNode*right):data(x),left(left),right(right){};
};

struct BST : public TreeNode {
    BST(int x):TreeNode(x){};
    BST():TreeNode(){};
    BST(int x,TreeNode* left,TreeNode* right):TreeNode(x,left,right){};
};



#endif