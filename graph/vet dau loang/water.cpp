#include <iostream>
#include <vector>
#include <queue>
#include <ctime>
#define MAX (100 + 1)

using namespace std;
int M;
int N;

int water[MAX][MAX]{};
bool check[MAX][MAX]{};
int h[MAX][MAX];
int x_index[] = {0,1,0,-1};
int y_index[] = {1,0,-1,0};

void gen_api(){
    int i;
    int j;
    time_t t;
    srand(unsigned(&t));
    int r;
    for (int i = 1; i <= M; i++){
        for (int j = 1; j <= N; j++){
            r = rand()  % 6;
            h[i][j] = r;
        }
    }
}

void read(){
    for (int i = 1; i <= M; i++){
        for (int j = 1; j <= N; j++){
            cin >> h[i][j];    
        }    
    }    
}

bool isBorder(int i, int j){
    if (i == M || i == 1)
        return true;
    if (j == N || j == 1)
        return true;
    return false;
}

bool isInside(int i,int j){
    if (i < 1 || i > M)
        return false;
    if (j < 1 || j > N)
        return false;
    return true;
}

bool loang(int i, int j,int k){
    for (int x = 1; x <= M; ++x)
    for (int y = 1; y <= N; ++y)
      check[x][y] = false;
    check[i][j] = true;
    queue <int> que_i;
    queue <int> que_j;
    que_i.push(i);
    que_j.push(j);
    bool result = true;
    while (que_i.empty() == false && que_j.empty() == false){
        int u = que_i.front();
        int v = que_j.front();
        que_i.pop();
        que_j.pop();
        for (int k = 0; k < 4; k++){
            int i_new = u + x_index[k];
            int j_new = v + y_index[k];
            if (check[i_new][j_new] == false){
                if (!isInside(i_new,j_new))
                    continue;
                if (h[i_new][j_new] >= k)
                    continue;
                if (isBorder(i_new,j_new))
                   result = false;
                check[i_new][j_new] = true;
                que_i.push(i_new);
                que_j.push(j_new);
            }
        }
    }
    return result;
}

void updateWater(int k){
    for (int i = 2; i < M; i++){
        for (int j = 2; j < N; j++){
            water[i][j] = k - h[i][j];
        }    
    }    
}

void solve(){
    for (int i = 2; i < M; i++){
        for (int j = 2; j < N; j++){
            if (water[i][j] == 0){
                int k = h[i][j] + 1;
                while(loang(i,j,k)){
                    k++;
                }
                --k;
                updateWater(k);
            }
        }    
    }
}

void show(){
    int sum = 0;
    for (int i = 2; i < M; i++){
        for (int j = 2; j < N; j++){
            sum += water[i][j];
        }
    }
    cout << "sum of water: " << sum << endl;
}

void show_mo_hinh(){
    for (int i = 1; i <= M; i++){
        for (int j = 1; j <= N; j++){
            cout << h[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(){
    cin >> M;
    cin >> N;
    gen_api();
    show_mo_hinh();
    solve();
    show();
    return 0;    
}