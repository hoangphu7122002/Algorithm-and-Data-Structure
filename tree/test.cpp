#include <iostream>
using namespace std;

int main(){
    int X[8][8]{};
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cin >> X[i][j];
        }
    }
    int a[64]{};
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (X[i][j] >= 0)
            a[X[i][j]]++;
        }
    }
    for (int i = 0; i < 64;i++){
        if (a[i] == 0)
            cout << i << ' ';
    }
    return 0;
}