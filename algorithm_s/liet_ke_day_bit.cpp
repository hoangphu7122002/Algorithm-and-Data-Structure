#include <iostream>
#include <queue>
using namespace std;

void show(bool* check, int n){
    for (int i = 0; i < n; i++){
        cout << 1 - check[i] << ' ';
    }
    cout << endl;
}

void Try(int k, bool* check, int n){
    if (k == n){
        show(check,n);
        return;
    }
    check[k] = true;
    Try(k + 1,check,n);
    check[k] = false;
    Try(k + 1,check,n); 
}


int main() {
    int n;
    cin >> n;
    bool* check = new bool[n];
    Try(0,check,n);
    delete[] check;
    return 0;
}