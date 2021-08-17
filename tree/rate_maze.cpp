#include <iostream>
using namespace std;

int path[4][4]{};
int solve[4][4]{};

void show(){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            cout << solve[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

bool check(int i, int j){
    if (path[i][j] != 0)
        return false;
    if (i < 0 || i >= 4)
        return false;
    if (j < 0 || j >= 4)
        return false;
    return true;
}

bool Try(int i, int j){
    if (i == 3 && j == 3 && path[i][j] == 0){
        solve[i][j] = 1;
        show();
        return true;
    }
    if (check(i,j) == true){
        solve[i][j] = 1;
        if (Try(i,j + 1) == true){
            return true;
        }
        if (Try(i + 1,j) == true){
            return true;
        }
        if (Try(i,j - 1) == true){
            return true;
        }
        if (Try(i - 1,j) == true){
            return true;
        }  
    }
    solve[i][j] = 0;
    return false;
}

void Try_s(int i, int j){
    if (i < 0 || j < 0)
        return;
    if (i == 3 && j == 3 && path[i][j] == 0){
        solve[i][j] = 1;
        show();
        return;
    }
    for (int k = 0; k <= 1; k++){
        int i_new = i + 1 - k;
        int j_new = j + k;
        if (check(i_new,j_new) == 1){
            solve[i][j] = 1; 
            Try_s(i_new,j_new);
            solve[i][j] = 0;
        }
    }
}

int main(){
    path[1][2] = -1;
    path[0][1] = -1;
    Try_s(0,0);
    return 0;
}