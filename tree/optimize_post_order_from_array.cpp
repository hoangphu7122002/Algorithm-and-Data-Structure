#include <iostream>
#include <map>
using namespace std;

int preIndex = 0;

int search(int arr[], int str, int end, int data){
    for (int i = str; i <= end; i++){
        if (arr[i] == data)
            return i;
    }
    return -1;
}

void post_order(int arr[], int pre[], int str, int end){
    if (str > end)
        return;
    int index = search(arr,str,end,pre[preIndex++]);
    post_order(arr,pre,str,index - 1);
    post_order(arr,pre,index + 1,end); 
    cout << arr[index] << ' ';
}

//hashing

int main()
{
    int in[] = { 4, 2, 5, 1, 3, 6 };
    int pre[] = { 1, 2, 4, 5, 3, 6 };
    int n = sizeof(in) / sizeof(in[0]);
    cout << "Postorder traversal " << endl;
    post_order(in, pre, 0, n - 1);
    return 0;
}