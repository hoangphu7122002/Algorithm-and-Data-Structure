//truong hop do thi day
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>

using namespace std;

const int maxV = 100;
const int maxE = (maxV - 1) *  maxV / 2;
string inputFile = "Mintree.inp";
string outputFile = "Mintree.out";
int c[maxV][maxV];
int d[maxV];
bool Free[maxV];
int Trace[maxV];
int n;
int m;
bool connected; //kiem tra xem du n - 1 canh chua
const int maxC = 101;

//Prototyp
void Text();
void LoadGraph();
void init();
void Prim();
void show();

template<class T>
void RESET(T* a,T b){
    for (int i = 1; i <= m; i++){
        a[i] = b;
    }
}

void Text(){

};

void LoadGraph(){
    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++){
        RESET(c[i],0);
        c[i][i] = maxC;
    }
    for (int i = 1; i <= m; i++){
        int u;
        int v;
        cin >> u >> v;
        int w;
        cin >> w;
        c[u][v] = w;
        c[v][u] = c[u][v];
    }
}

void Init(){
    RESET(d,maxC);
    d[1] = 0;
    RESET(Free,true);
}

void Prim(){
    connected = true;
    int u;
    int min;
    for (int k = 1; k <= n; k++){
        //chon dinh co bac nho nhat chua duoc chon
        u = 0;
        min = maxC;
        for (int i = 1; i <= n; i++){
            if (Free[i] == true && d[i] < min){
                min = d[i];
                u = i;
            }
        }
        if (u == 0){
            connected = false;
            break;
        }
        Free[u] = false;
        for (int v = 1; v <= n; v++){
            if (Free[v] == true && (d[v] > c[u][v])){
                d[v] = c[u][v];
                Trace[v] = u;
            }
        }
    }
}

void show(){
    if (connected == false){
        cout << "khong lien thong" << endl;
        return;
    }
    int w = 0;
    for (int v = 2; v <= n; v++){
        w = w + c[Trace[v]][v];
    }
    cout << w << endl;
}

int main() {
    return 0;
}
