#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int data){
        this->data = data;
        left = right = NULL;
    }
};

void addNode(node* &root, int data){
    if (root == NULL){
        root = new node(data);
        return;
    }
    if(root->data > data){
        node* temp = new node(data);
        root->left = temp;
    }
    else {
        node* temp = new node(data);
        root->right = temp;
    }
}

void printInorder(node* root){
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->data << endl;
    printInorder(root->right);
}

void Inorder(node* root){
    stack <node*> stk;
    node* temp = root;
    while(temp != NULL || stk.empty() == false){
        while (temp != NULL){
            stk.push(temp);
            temp = temp->left;
        }
        temp = stk.top();
        stk.pop();
        cout << temp->data << ' ';
        temp = temp->right;
    }   
}

void Moris_traversal(node* root){
    node* current = root;
    node* pre;
    while(current != NULL){
        if (current->left == NULL){
            cout << current->data << ' ';
            current = current->right;
        }
        else {
            pre = current->left;
            while(pre->right != NULL && pre->right != current){
                pre = pre->right;
            }
            if (pre->right == NULL){
                pre->right = current;
                current = current->left;
            }
            else{
                pre->right = NULL;
                cout << current->data << ' ';
                current = current->right;
            }
        }
    }
} 

void Preorder_Traversal(node* root){
    if(root == NULL){
        return;
    }
    cout << root-> data << ' ';
    Preorder_Traversal(root->left);
    Preorder_Traversal(root->right);
}

void Postorder_Traversal(node* root){
    if (root == NULL)
        return;
    Postorder_Traversal(root->left);
    Postorder_Traversal(root->right);
    cout << root->data << ' ';
}

void print_current_level(node* root, int level){
    if (root == NULL)
        return;
    if (level == 1){
        cout << root->data << " ";
    }
    else {
        print_current_level(root->left,level - 1);
        print_current_level(root->right,level - 1);
    }
}

int height(node* root){
    if (root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    if (left > right){
        return left + 1;
    }
    return right + 1;
}

void print_level_order(node* root){
    if (root == NULL)
        return;
    int d = height(root);
    for (int i = 1; i <= d; i++){
        print_current_level(root,i);
    }
}

void level_order(node* root){
    if (root == NULL){
        return;
    }
    queue <node*> que;
    node* temp = root;
    que.push(temp);
    while(que.empty() == false){
        que.push(que.front()->left);
        que.push(que.front()->right);
        cout << que.front()->data << ' ';
        que.pop();
    }
}

int Search(int* arr, int n, int x){
    for (int i = 0; i < n; i++){
        if (arr[i] == x)
            return i;
    }
    return -1;
}

void Print_post_order_from_array(int in[], int pre[], int n){
    int root = Search(in,n,pre[0]);
    if (root == -1) return;
    if (root != 0){
        Print_post_order_from_array(in,pre + 1,root);
    }
    if (root != n - 1){
        Print_post_order_from_array(in + root + 1,pre + root + 1,n - root - 1);
    }
    cout << pre[0] << ' ';
}



int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    level_order(root);
    return 0;
}