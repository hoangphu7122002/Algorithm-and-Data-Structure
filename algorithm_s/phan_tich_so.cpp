#include <iostream>
using namespace std;

int T[1000];
int x[1000];

void show(int* x, int size){
    for (int i = 1; i <= size; i++){
        cout << x[i];
        if (i != size)
            cout << " + ";
    }
    cout << endl;
}

void Try(int n, int i){
    for (int j = x[i - 1]; j <= (n - T[i - 1])/2; j++){
        x[i] = j;  
        T[i] = T[i - 1] + x[i];
        Try(n,i + 1);
    }   
    x[i] = n - T[i - 1];
    show(x,i);
}


int main() {
    int n;
    cin >> n;
    x[0] = 1;
    T[0] = 0;
    Try(n,1);
    return 0;
}