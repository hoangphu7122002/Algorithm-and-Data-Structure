#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val{0},left{NULL},right{NULL}{};
    TreeNode(int x):val{x},left(NULL),right{NULL}{};
    TreeNode(int x,TreeNode* left,TreeNode* right):val{x},left{left},right{right}{};
};

//reference to geeks for geeks

//-----------------------
//method 1: vector contain the path from root to node can find
//to find LCA, loop element from path array and check it
bool find(TreeNode* root,vector <int>&path,int key){
    if (root == NULL){
        return false;
    }
    path.push_back(root->val);
    if (root->val == key){
        return true;
    }
    if (root->left && find(root->left,path,key))
        return true;
    if (root->right && find(root->right,path,key))
        return true;
    //the path is not choose
    path.pop_back();
    return false;
}

//O(n)
int findLCA(TreeNode* root,int n1,int n2){
    vector <int> path1,path2;
    if (!find(root,path1,n1) || !find(root,path2,n2)){
        return -1;
    }
    //the furthest ancestor
    int i;
    for (i = 0; i < min(path1.size(),path2.size()); i++){
        if (path1[i] != path2[i]){
            break;
        }
    }
    return path1[i - 1];
}
//---------------
//method 2: recursive traversal;
//the traversal from the bottom up but it assumes that n1 and n2 are found
TreeNode* ptrfindLCA(TreeNode* root,int n1,int n2){
    if (root == NULL){
        return NULL; 
    }
    if (root->val == n1 || root->val == n2){
        return root;
    }
    //recursion
    TreeNode* left_LCA = ptrfindLCA(root,n1,n2);
    TreeNode* right_LCA = ptrfindLCA(root,n1,n2);
    
    //n1,n2 are belong to two branch
    
    if (left_LCA && right_LCA){
        return root;
    }
    
    return (left_LCA != NULL)?left_LCA:right_LCA;
    
}

//-----------------------
//method 3: check and recursive: it combine method 1 and method 2
bool find(TreeNode* root,int key){
    if (root == NULL){
        return false;
    }
    if (root->val == key){
        return true;
    }
    if (find(root->left,key)||find(root->right,key)){
        return true;
    }
    return false;
}

TreeNode* LCAFake(TreeNode* root,int n1,int n2,bool &v1,bool& v2){
    //BaseCase
    if (root == NULL){
        return NULL;
    }
    if (root->val == n1){
        v1 = true;
        return root;
    }
    if (root->val == n2){
        v2 = true;
        return root;
    }
    TreeNode* LCA_left = LCAFake(root->left,n1,n2,v1,v2);
    TreeNode* LCA_right = LCAFake(root->right,n1,n2,v1,v2);
    if (LCA_left && LCA_right){
        return root;
    }
    return (LCA_left != NULL) ? LCA_left:LCA_right;
}

TreeNode* LCA(TreeNode* root,int n1,int n2){
    bool v1 = false;
    bool v2 = false;
    TreeNode* LCA_node = LCAFake(root,n1,n2,v1,v2);
    if (v1 && v2 || v1 && find(root,n2) || v2 && find(root,n1)) {
        return LCA_node;
    }
    return NULL;
}

//LCS_BST;




