#include <iostream>
using namespace std;

int path[4][4]{};

void show(){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            cout << path[i][j] << ' ';
        }
        cout << endl;
    }
}

//vet_dau_loang
int count(){
    if (path[0][0] == -1)
        return 0;
    for (int i = 0; i < 4; i++){
        if (path[i][0] == 0){
            path[i][0] = 1;
        }
        else break;
    }
    for (int i = 0; i < 4; i++){
        if (path[0][i] >= 0)
            path[0][i] = 1;
        else
            break;
    }
    for (int i = 1; i < 4; i++){
        for (int j = 1; j < 4; j++){
            if (path[i][j] == -1)
                continue;
            if (path[i][j - 1] > 0)
                path[i][j] += path[i][j - 1];
            if (path[i - 1][j] > 0)
                path[i][j] += path[i - 1][j];
        }
    }
    return path[3][3];
}

int main(){
    path[1][1] = -1;
    path[2][0] = -1;
    cout << count() << endl;
    show();
    return 0;
}