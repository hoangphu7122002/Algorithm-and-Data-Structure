#include <iostream>
#include <ctime>
using namespace std;

const int MAX_R = 100;
const int MAX_C = 100;

char p[MAX_R][MAX_C];

int m;
int n;
//(0 , 1) (1, 0) (0,-1) (-1,0)
int index_x[] = {0,1,0,-1};
int index_y[] = {1,0,-1,0};
int num_grass = 10;

bool check(int i, int j){
    if (i < 0 || i >= m){
        return false;
    }
    if (j < 0 || j >= n){
        return false;
    }
    if (p[i][j] == '.')
        return false;
    return true; 
}

void loang(int i,int j){
    p[i][j] = '.';
    for (int k = 0; k < 4; k++){
        if (check(i + index_x[k],j + index_y[k]) == true)
            loang(i + index_x[k],j + index_y[k]);
    }
}

void gen_mo_hinh(){
    int inum = 0;
    time_t t;
    int r;
    int row;
    int col;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            p[i][j] = '.';
        }
    }
    srand(unsigned(&t));
    while(inum < num_grass){
        r = rand() % (m * n);
        row = r / m;
        col = r - row * m;
        if (p[row][col] == '.'){
            inum++;
            p[row][col] = '#';
        }
    }
}

void show(){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << p[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(){
    cin >> m;
    cin >> n;
    int dem = 0;
    gen_mo_hinh();
    show();
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (p[i][j] == '#'){
                loang(i,j);
                dem++; 
            }
        }
    }
    cout << "result " << dem;
    return 0;
}