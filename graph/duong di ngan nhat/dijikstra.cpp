#include <iostream>
using namespace std;


#define oo 99999
const int MAX = 100;
int a[MAX][MAX];
int V;
int E;
int track[MAX];
int d[MAX];
int root;
int child;
bool Free[MAX];

void show_track(int u, int v){
    while (u != v){
        cout << v << "<-";
        v = track[v];
    }
    cout << u << endl;
}

void readable(){
    cin >> V;
    cin >> E;
    cin >> root;
    cin >> child;
    for (int i = 1; i <= V; i++){
        RESET(a[i],oo);
    }
    RESET(Free,true);
    while (E--){
        int u;
        int v;
        cin >> u;
        cin >> v;
        int w;
        cin >> w;
        a[u][v] = w;
    }
}

template<class T>
void RESET(T* a,T b){
    for (int i = 1; i <= V; i++){
        a[i] = b;
    }
}

void Dijkstra(int u){
    int min;
    init(u);
    Free[u] = false;
    while (true){
        u = 0;
        min = oo;
        for (int i = 1; i <= V; i++){
            if (Free[i] == true && d[i] < min){
                min = d[i];
                u = i;
            }
        }
        if (u == 0 || u == child){
                break;
        }
        Free[u] = false;
        for (int v = 1; v <= V; v++){
            if (Free[v] == true && d[v] > d[u] + a[u][v]){
                d[v] = d[u] + a[u][v];
                track[v] = u;
            }
        }
    }
}

void init(int u){
    for (int i = 1; i <= V; i++){
        d[i] = oo;
    }
    d[u] = 0;
}

int main() {
    readable();
    Dijkstra(root);
    show_track(root,child);
}
