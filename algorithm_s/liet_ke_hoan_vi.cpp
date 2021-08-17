#include <iostream>
using namespace std;

void show(int* arr, int n){
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void Try(int k, int n, bool* check, int* arr){
    for (int i = 1; i <= n; i++) {
        if (check[i] == false){
            arr[k] = i;
            check[i] = true;
            if (k == n){
                show(arr,n);
            }
            else {
                Try(k+1,n,check,arr);
            }
            check[i] = false;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n + 1];
    bool* check = new bool[n + 1]{};
    Try(1,n,check,arr);
    delete[] arr;
    delete[] check;
    return 0;
}