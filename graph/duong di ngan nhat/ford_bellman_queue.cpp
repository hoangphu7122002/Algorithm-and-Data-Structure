//O(m) nhưng chỉ dùng được cho đồ thị có trọng số không âm
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define X first
#define Y second
#define oo 99999
typedef pair<int,int> ii;
vector <ii> a[712];
int V;
int E;
int d[712];
bool inqueue[712];
int track[712];

//prototype
void RESET(int*,int);

void RESET(int* a,int b){
    for (int i = 1; i <= V; i++){
        a[i] = b;
    }
}

void bellman_ford(int u){
    queue <int> que;
    RESET(d,oo);
    d[u] = 0;
    inqueue[u] = true;
    que.push(u);
    while (que.empty() == 0){
        u = que.front();
        inqueue[u] = false;
        que.pop();
        for (int i = 0; i < a[u].size(); i++){
           int v = a[u][i].Y;
           int uv = a[u][i].X;
           if (d[v] > d[u] + uv){
               d[v] = d[u] + uv;
               if (!inqueue[v]){
                   que.push(v);
                   track[v] = u;
                   inqueue[v] = true;
                   //resonable
               }
           } 
        }
    }
}

void show_track(int u, int v){
    while (u != v){
        cout << v << "<-";
        v = track[v];
    }
    cout << u << endl;
}

int main(){
    int u;
    int v;
    cin >> V;
    cin >> E;
    cin >> u;
    cin >> v;
    while (E--){
        int u;
        int v;
        cin >> u >> v;
        int w;
        cin >> w;
        a[u].push_back(ii(w,v));
        a[v].push_back(ii(w,u));
    }
    bellman_ford(u);
    cout << d[v] << endl;
}
