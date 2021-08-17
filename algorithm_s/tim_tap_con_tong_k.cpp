#include <iostream>
using namespace std;
 
void show(int* arr, bool* check, int n){
    for (int i = 0; i < n; i++) {
        if (check[i] == true)   {
            cout << arr[i];
            if (i != n - 1) cout << ' ';
        }
    }
    cout << endl;
} 

void Try(int i,int* arr,bool* check, int n, int k){
    if (i == n + 1 || k < 0){
        return;
    }
    if (k == 0){
        show(arr,check,n);
        return;
    }
    check[i] = true;
    k = k - arr[i];
    Try(i + 1,arr,check,n,k);
    check[i] = false;
    k = k + arr[i];
    Try(i + 1,arr,check,n,k);
}

int main(){
    int n;
    cin >> n;
    int k;
    cin >> k;
    
    int* arr = new int[n];
    bool* check = new bool[n]{};

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Try(0,arr,check,n,k);

    delete[] arr;
    delete[] check;
    return 0;
}