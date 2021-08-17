#include <iostream>
using namespace std;

int X[8][8]{};
int step = 0;
int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

//prototype
void solve();
bool Try(int,int,int);
bool check(int,int);
void show();

void solve(){
    if (Try(1,1,step) == false){
        cout << "no solve";
    }
    else {
        show();
    }
}

bool Try(int i,int j,int step){
    if (step == 64){
        return true;
    }
    int next_move_x;
    int next_move_y;
    for (int k = 0; k < 8; k++){
        next_move_x = i + xMove[k];
        next_move_y = j + yMove[k];
        if (check(next_move_x,next_move_y) == true){
            X[next_move_x][next_move_y] = step;
            if (Try(next_move_x,next_move_y,step + 1) == true)
                return true;
            else {
                X[next_move_x][next_move_y] = -1;
            }
        }
    }
    return false;
}

bool check(int i, int j){
    if (X[i][j] >= 0)
        return false;
    if (i < 0 || i >= 8)
        return false;
    if (j < 0 || j >= 8)
        return false;
    return true;
}

void show(){
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cout << X[i][j] << ' ';
        }
        cout << endl;
    }
}
int main(){
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            X[i][j] = -1;
        }
    }
    X[1][1] = 0;
    step = 1;
    solve();
    return 0;
}