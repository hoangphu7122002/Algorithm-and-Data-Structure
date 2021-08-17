#include <iostream>
using namespace std;

const int Max = 20;
const int MaxC = 20 * 100 + 1;
int C[Max + 1][Max + 1];
//bien thu kha nang
int X[Max + 2];
//bien gan
int BestWay[Max + 2];
int T[Max + 2];
bool Free[Max + 1]{};
int MinSpending;
int n;
int m;
int count = 0;

void Try(int i){
    for (int j = 2; j <= n; j++) {
        if (Free[j] == false){
            X[i] = j;
            T[i] = T[i - 1] + C[i - 1][j];
            if (T[i] < MinSpending){
                if (i < n){
                    Free[j] = true;
                    Try(i + 1);
                    Free[j] = false;
                }
                else {
                    if (T[i] + C[X[n]][1] < MinSpending){
                        for (int k = 2; k <= n; k++){
                            BestWay[k] = X[k];
                        }
                        BestWay[n + 1] = 1;
                        MinSpending = T[i] + C[X[n]][1];
                    }
                }
            }   
        }
    }
}

void show(){
    if (MinSpending == MaxC)
        cout << "No Solution" << endl;
    for (int i = 1; i <= n + 1; i++) {
        cout << BestWay[i];
        if (i != n + 1){
            cout << "->";
        }
    }
    cout << endl;
    cout << "Cost: " << MinSpending << endl;
}

int main() {
    cin >> n;
    cin >> m;
    

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == j)
                C[i][j] = 0;
            else
                C[i][j] = MaxC; //+ vo cung
        }
    }

    for (int k = 1; k <= m; k++) {
        int i;
        int j;
        cin >> i;
        cin >> j;
        cin >> C[i][j];
        C[j][i] = C[i][j]; 
    }

    //khoi tao hanh trinh
    Free[1] = true;
    X[1] = 1;
    T[1] = 0;
    BestWay[1] = 1;
    MinSpending = MaxC;

    Try(2);
    show();
    return 0;
}