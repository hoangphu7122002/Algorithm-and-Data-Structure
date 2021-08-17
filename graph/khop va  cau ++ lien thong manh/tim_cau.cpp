#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100;
#define oo 101
int V;
int E;
bool a[N][N]{};
int cnt = 0;
int Numbering[N];
int Low[N];
int numC[N];
bool mark[N];

template<class T>
void Reset(T* a, T b){
    for (int i = 1; i <= V; i++){
        a[i] = b;
    }
}

void visit(int u){
    Low[u] = oo;
    Numbering[u] = cnt++;
    for (int v = 1; v <= V; v++){
        if (a[u][v] == true){
            a[v][u] = false;
            if (Numbering[v] == -1){
                visit(v);
                if (Low[v] > Numbering[u]) {
                    cout << "Bridge: " << u << ' ' << v << endl;
                }
                Low[u] = min(Low[u],Low[v]);
            }
            else {
                Low[u] = min(Low[u],Numbering[v]);
            }
        }
    }
}

void dem_khop(int u){
    Numbering[u] = cnt++;
    for (int v = 1; v <= V; v++) {
        if (a[u][v] == true){
            if (Numbering[v] == -1){
                numC[u]++;
                dem_khop(v);
                if (Low[v] >= Numbering[u]){
                    mark[u] = true;
                }
                Low[u] = min(Low[u],Low[v]);
            }
            else{
                Low[u] = min(Low[u],Numbering[v]);
            }
        }
    }
}

int main() {
    cin >> V;
    cin >> E;
    while (E--){
        int u, v;
        cin >> u >> v;
        a[u][v] = true;
        a[v][u] = true; 
    }
    Reset(Numbering,-1);
    Reset(mark,false);
    Reset(Low,oo);
    Reset(numC,0);
    for (int i = 1; i <= V; i++){
        if (Numbering[i] == -1){
            dem_khop(i);
            if (numC[i] < 2){
                mark[i] = false;
            }
        }
    }
    for (int i = 1; i <= V; i++){
        if (mark[i] == true)
            cout << i << ' ';
    }
    return 0;
}