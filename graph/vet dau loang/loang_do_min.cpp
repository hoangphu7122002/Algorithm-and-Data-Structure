#include <iostream>
#include <ctime>
using namespace std;

#define EMPTY 0
#define MINE 9

int p[9][9]{};
int MAXROW = 9;
int MAXCOL = 9;
int num_min = 15;

int mi_count(int row,int col){
    int mi_near = 0;
    for (int i = -1; i < 2; i++){
        for (int j = -1; j < 2; j++){
            int new_row = row + i;
            int new_col = col + j;
            if (new_row < MAXROW && new_col < MAXCOL && p[new_row][new_col] == MINE){
                mi_near++;
            }
        }
    }
    return mi_near;
}

void gen_min(){
    time_t t;
    int r;
    int row;
    int col;
    int imin = 0;
    srand(unsigned(time(&t)));
    while (imin++ < num_min){
        r = rand() % ((MAXROW) * (MAXCOL));
        row = r / MAXROW;
        col = r - row * MAXROW;
        int should_add = 1;
        if (p[row][col] != EMPTY){
            continue;
        }
        for (int i = -1; i <= 2 && i != 0; i++){
            for (int j = -1; j <= 2 && j != 0; j++){
                if (p[row + i][col + j] != MINE && mi_count(row + i,col + j) > 3)
                    should_add = 0; 
            }
        }
        if (should_add == 1){
            p[row][col] = MINE;
        }
    }
}

void gen_num(){
    for (int i = 0; i < MAXROW; i++){
        for (int j = 0; j < MAXROW; j++){
            if (p[i][j] == EMPTY){
                p[i][j] = mi_count(i,j);
            }
        }
    }
}

void show(){
    for (int i = 0; i < MAXROW; i++){
        for (int j = 0; j < MAXCOL; j++){
            cout << p[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(){
    gen_min();
    gen_num();
    show();
    return 0;
}