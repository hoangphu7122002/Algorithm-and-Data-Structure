#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <typeinfo>
#include <algorithm>
#define oo 9999

using namespace std;

const int MAX = 100;
int a[MAX][MAX];
int V;
int E;
int track[MAX][MAX];
int d[MAX];

void readable(){
    cin >> V;
    cin >> E;
    init();
    while (E--){
        int u,v;
        cin >> u >> v;
        int w;
        cin >> w;
        a[u][v] = w;
    }
}

void init(){
    for (int i = 1; i <= V; i++){
        d[i] = oo;
    }
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

void floyd_warshall(){
    for (int u = 1; u <= V; u++){
        for (int v = 1; v <= V; v++){
            //lam vay cho de thuan tien
            track[u][v] = v;
        }
    }
    for (int k = 1; k <= V; k++){
        for (int u = 1; u <= V; u++){
            for (int v = 1; v <= V; v++){
                if (a[u][v] > a[u][k] + a[k][v])
                    a[u][v] = a[u][k] + a[k][v];
                    track[u][v] = track[u][k];
            }
        }
    }
}

void show_track(int S, int F){
    if (a[S][F] == oo){
        cout << "has no path" << endl;
    }   
    else {
        cout << "distance: " << a[S][F] << endl;
        while (S != F){
            cout << S << "->";
            S = track[S][F];
        }
        cout << F << endl;
    }
}

int main() {
    return 0;
}