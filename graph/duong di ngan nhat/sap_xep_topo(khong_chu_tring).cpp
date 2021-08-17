#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;

const int oo = 9999;
const int MAX = 1000;
int V;
int E;
int S;
int F;
int a[MAX][MAX];
int track[MAX];
int d[MAX];
int order_list[MAX];
//kiem tra xem do thi co chu trinh hay khong
int visit[MAX];
bool check_cycle = false;

//prototype
void init(int);
void dfs(int);
void readable();
void show_track(int,int);
void number();
void find_path();
void algorithm();

void init(int u){
    for (int i = 1; i <= V; i++){
        d[i] = oo;
    }
    d[u] = 0;
    for (int i = 1; i <= V; i++){
        for (int j = 1; j <= V; j++){
            if (i == j){
                a[i][j] = 0;
                continue;
            }
            a[i][j] = oo;
        }
    }
}

void dfs(int u){
    visit[u] = 1;
    for (int v = 1; v <= V; v++){
        if (visit[v] == 0)
            dfs(v);
        else if (visit[v] == 1){
            check_cycle = true;
        }
    }    
    visit[u] = 2;
}

void readable(){
    cin >> V;
    cin >> E;
    cin >> S;
    cin >> F;
    init(S);
    while (E--){
        int u,v;
        cin >> u >> v;
        int w;
        cin >> w;
        a[u][v] = w;
    }
}

void show_track(int u, int v){
    cout << d[v] << endl;
    while (u != v){
        cout << v << "<-";
        v = track[v];
    }
    cout << u << endl;
}

//phao co thuat toan kiem tra ton tai chu trinh

//thuat toan danh so Topo
void Number(){
    int deg[MAX]{};
    for (int u = 1; u <= V; u++){
        for (int v = 1; v <= V; v++){
            if (u != v && a[v][u] < 0){
                deg[u]++;
            }
        }
    }
    int count = 0;
    for (int i = 1; i <= V; i++){
        if (deg[i] < oo){
            count++;
            order_list[count] = i;
        }
    }
    int front = 1;
    while (front <= count){
        int u = order_list[front];
        front++;
        for (int v = 1; v <= V; v++){
            if (u != v && a[u][v] != oo){
                deg[v]--;
                if (deg[v] == 0){
                    count++;
                    order_list[count] = v;
                }
            }
        }
    }
} 

//thuat toan quy hoach dong tim duong di nho nhat:
void find_path(){
    for (int i = 1; i <= V - 1; i++){
        for (int j = i + 1; j <= V; j++){
            int u = order_list[i];
            int v = order_list[j];
            if (a[u][v] != oo && d[v] > d[u] + a[u][v]){
                d[v] = d[u] + a[u][v]; 
                track[v] = u;
            }
        }
    }
}

void algorithm(){
    if (check_cycle == true){
        Number();
        find_path();
        show_track(S,F);
    }
    else {
        cout << "khong thuc hien topo sort duoc" << endl;
    }
}