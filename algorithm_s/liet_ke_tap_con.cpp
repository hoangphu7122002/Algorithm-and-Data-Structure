#include <iostream>
using namespace std;

void show(int* arr, int n, bool* check){
    for (int i = 0; i < n; i++){
        if (check[i] == true) cout << arr[i] << ' ';
    }
    cout << endl;
}

void Try(int k, int* arr, bool* check, int n){
    if (k == n){
        show(arr,n,check);
        return;
    }
    check[k] = true;
    Try(k + 1,arr,check,n);
    check[k] = false;
    Try(k + 1,arr,check,n);
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    bool* check = new bool[n]{};
    Try(0,arr,check,n);
    delete[] arr;
    delete[] check;
    return 0;
}