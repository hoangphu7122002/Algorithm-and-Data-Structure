#include <iostream>
using namespace std;

bool a[1001]{}; 
bool b[2001]{}; 
bool c[2000]{}; 
int x[1000]{};

void show(int n){
    for (int i = 1; i <= n; i++){
        cout << x[i];
        if (i != n){
            cout << ' ';
        }
    }
    cout << endl;
}

void Try(int i, int n){
    for (int j = 1; j <= n; j++) {
        if (i == n + 1){
            show(n);     
            return;       
        }
        if (a[j] == false && b[j + i] == false && c[j - i + n] == false) {
            x[i] = j;
            a[j] = true;
            b[j + i] = true;
            c[j - i + n] = true;
            Try(i + 1,n);
            a[j] = false;
            b[j + i] = false;
            c[j - i + n] = false;
        }
    }
}

int main() {
    int n;
    cin >> n;
    Try(1,n);
    return 0;
}