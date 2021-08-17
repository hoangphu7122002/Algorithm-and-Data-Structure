#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAX = 100;
vector <int> a[712];
vector <int> Trace;
int Trace_s[712];
bool check[712]{};
int n;
int m;

void DFS(int u){
    check[u] = true;
    if (Trace.size() == n - 1) {
        return;
    }
    for (int i = 0; i < a[u].size(); i++){
        int v = a[u][i];
        if (check[v] == false){
            Trace.push_back(v);
            DFS(v);
        }
    }
}

void DFS_stack(int u){
    stack <int> stk;
    check[u] = true;
    stk.push(u);
    while (stk.empty() == false){
        int m = stk.top();
        stk.pop();
        for (int i = 0; i < a[m].size(); i++){
            int n = a[m][i];
            if (check[n] == false){
                Trace.push_back(n);
                check[n] = true;
                stk.push(m);
                stk.push(n);
                break;
            }
        }
    }
}

void DFS_dem_lien_thong(){
    int dem = 0;
    for (int i = 1; i <= n; i++){
        if (check[i] == false){
            DFS(i);
            dem++;
        }
    }
    cout << dem;
}

void show(int u) {
    cout << u << "->";
    for (int i = 0; i < Trace.size(); i++){
        cout << Trace[i];
        cout << "->";
    }
    cout << u << endl;
}
int main() {
    cin >> n;
    cin >> m;
    while (m--){
        int u;
        int v;
        cin >> u;
        cin >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    DFS_dem_lien_thong();
    return 0;
}