#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX = 100;
vector <int> a[MAX];
stack <int> stk;
int n, m;
int num[MAX];
int low[MAX];
int connect[MAX];
int cnt = 0;
vector <int> component[MAX];
int size_c = 0;

void RESET(int* a, int b){
    for (int i = 0; i < MAX; i++){
        a[i] = b;
    }
}

void Tarjan(int u){
    num[u] = low[u] = ++cnt;
    stk.push(u);
    connect[u] = 1;
    for (int v : a[u]){
        if (num[v] == 0){
            Tarjan(v);
        }
        if (connect[v] == 1){
            low[u] = min(low[u],low[v]);
        }
    }
    if (low[u] == num[u]){
        while (1){
            int v = stk.top();
            connect[v] = 0;
            component[size_c].push_back(v);
            stk.pop();
            if (v == u)
                break;
        }
        size_c++;
    }
}

int main() {
    cin >> n >> m;
    while (m--){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
    }

    RESET(num,0);
    RESET(low,0);
    RESET(connect,0);

    for (int i = 1; i <= n; i++){
        if (num[i] == 0)
            Tarjan(i);
    }
    for (int i = 0; i < size_c; i++){
        for (int j = 0; j < component[i].size(); j++)
            cout << component[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
