#include <iostream>
using namespace std;

const int Max = 100;
int N;
int minC = 100;
int T[101];
char Best[101];
char X[101];

void show(){
    for (int i = 1; i <= N; i++){
        cout << Best[i];
    } 
    cout << endl;
    cout << "Letter C: " << minC << endl;
}

void keepResult(){
    minC = T[N];
    for (int i = 1; i <= N; i++){
        Best[i] = X[i];
    }
}

bool same(int i, int l) {
    int j = i - l;
    for (int k = 0; k <= l - 1; k++){
        if (X[i - k] != X[j - k]){
            return false;
        }
    }
    return true;
}

bool check(int i){
    for (int l = 1; l <= i/2; l++) {
        if (same(i,l) == true){
            return false;
        }
    }
    return true;
}

void Try(int i){
    for (char j = 'A'; j <= 'C'; j++){
        X[i] = j;
        if (check(i) == true){
            if (j == 'C')
                T[i] = T[i - 1] + 1;
            else
                T[i] = T[i - 1];
            if (T[i] + (N - i)/4 < minC){
                if (i == N)
                    keepResult();
                else
                    Try(i + 1);
            }
        }
    }
}

int main() {
    cin >> N;
    Try(1);
    show();
    return 0;
}