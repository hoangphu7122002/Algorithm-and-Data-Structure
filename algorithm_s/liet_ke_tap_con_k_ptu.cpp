#include <iostream>
using namespace std;

bool check[1000];
int arr[1000];

void show(int n){
    for (int i = 0; i < n; i++){
        if (check[i] == true){
            cout << arr[i] << ' ';
        }
    }
    cout << endl;
}

void Try(int i, int n, int k, int size){
    if (i == n + 1){
        return;
    }
    if (size == k){
        show(n);
        size = 0;
        return;
    }
    check[i] = true;
    Try(i + 1,n,k,size + 1);
    check[i] = false;
    Try(i + 1,n,k,size);
} 

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    Try(0,n,k,0);
    return 0;
}