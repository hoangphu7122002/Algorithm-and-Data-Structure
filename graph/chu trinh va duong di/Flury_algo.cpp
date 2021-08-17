#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

#define oo 101
const int MAX = 100;
int V;
int E;
bool a[MAX][MAX]{};
int Numbering[MAX];
int Low[MAX];
vector <pair<int,int>> bridge;
int cnt = 1;
stack <int> stk;
vector <int> Euler_Cycle;
int check_odd_vertex = 1;
int b[101];

template <class T>
void RESET(T* a,T b){
    for (int i = 1; i <= V; i++){
        a[i] = b;
    }
}

void visit(int u){
    Numbering[u] = cnt++;
    for (int v = 1; v <= V; v++){
        if (a[u][v] == true){
            if (Numbering[v] == -1){
                visit(v);
                if (Low[v] > Numbering[u]){
                    bridge.push_back(make_pair(u,v));
                }
                Low[u] = min(Low[u],Low[v]);
            }
            else {
                Low[u] = min(Low[u],Numbering[v]);
            }
        }
    }
}

void Fleury(int u){
    stk.push(u);
    while (stk.empty() == false){
        int x = stk.top();
        stk.pop();
        for (int y = 1; y <= V; y++){
            if (a[x][y] == true){
                cout << "dmm" << endl;
                stk.push(y);
                a[x][y] = false;
                a[y][x] = false;
                break;
            }
        }
        Euler_Cycle.push_back(x);
    }
}

bool check(){
    int s,d;
    d = 0; //variable for count vertex has odd degree
    for (int i = 1; i <= V; i++){
        s = 0;
        for (int j = 1; j <= V; j++){
            s += a[i][j];
        }
        if (s % 2){
            d++;
            check_odd_vertex = i;
        }
    }
    if (d != 2)
        return false;
    return true;
}

void DDEULER(){
    stk.push(check_odd_vertex);
    while (stk.empty() == false){
        int x = stk.top();
        stk.pop();
        for (int y = 1; y <= V; y++){
            if (a[x][y] == true){
                cout << "dmm" << endl;
                stk.push(y);
                a[x][y] = false;
                a[y][x] = false;
                break;
            }
        }
        Euler_Cycle.push_back(x);
    }
}

void show();

void Try(int i){
    if (i == E + 1){
        for (int i = 0; i <= E; i++){
            cout << b[i] << ' ';
        }
        cout << endl;
        return;
    }
    for (int v = 1; v <= V; v++) {
        if (a[b[i - 1]][v] == true){
            a[b[i - 1]][v] = false;
            a[v][b[i - 1]] = false;
            b[i] = v;
            Try(i + 1);
            a[b[i - 1]][v] = true;
            a[v][b[i - 1]] = true;
        }
    }
}

int main() {
    cin >> V;
    cin >> E;
    int copy = E;
    while (copy--){
        int u, v;
        cin >> u >> v;
        a[u][v] = true;
        a[v][u] = true;
    }
    // RESET(Numbering,-1);
    // RESET(Low,oo);
    // for (int i = 1; i <= V; i++){
    //     if (Numbering[i] == -1){
    //         visit(i);
    //     }
    // }

    if (check() == true){
        b[0] = check_odd_vertex;
        Try(1);
    }
    else {
        cout << "Has_no_path" << endl;
    }
    return 0;
}