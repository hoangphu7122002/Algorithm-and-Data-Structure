#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int data){
        this->data = data;
        this->left = this->right = NULL;
    }
    node(){
        this->left = this->right = NULL;
    }
};

node* newNode(int data){
    node* temp = new node(data);
    return temp;
}

node* buildtree(int* in, int* pre, int str, int end, unordered_map<int,int>& hsm){
    static int preIndex = 0;
    if (str > end)
        return NULL;
    int index = hsm[pre[preIndex++]];
    node* root = newNode(in[index]);
    if (str == end){
        return root;
    }
    root->left = buildtree(in,pre,str,index - 1,hsm);
    root->right = buildtree(in,pre,index + 1,end,hsm);
    return root;
}

node* buildtree_main(int* in, int* pre, int str, int end){
    unordered_map <int,int> hsm;
    for (int i = str; i <= end; i++){
        hsm[in[i]] = i;
    }
    return buildtree(in,pre,str,end,hsm);
}

//built_tree_from_post_and_pre
node* build_tree(int* pre, int* post, int* preIndex, int l, int h, int size){
    if (*preIndex >= size || l > h)
        return NULL;
    node* root = new node(pre[*preIndex]);
    ++*preIndex;
    if (l == h)
        return root;
    int i;
    for (i = l; i <= h; i++){
        if (pre[*preIndex] == post[i]){
            break;
        }
    }
    if (i <= h){
        root->left = build_tree(pre,post,preIndex,l,i,size);
        root->right = build_tree(pre,post,preIndex,i + 1,h,size);
    }
    return root;
}

void printInorder (node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout<<node->data<<" ";
    printInorder(node->right);
}

int main ()
{
    int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    int size = sizeof( pre ) / sizeof( pre[0] );
    int a = 0;
    node *root = build_tree(pre, post,&a,0,size - 1,size);
 
    cout<<"Inorder traversal of the constructed tree: \n";
    printInorder(root);
 
    return 0;
}