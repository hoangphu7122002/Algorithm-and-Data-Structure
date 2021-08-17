#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 100;
bool a[MAX][MAX]{};
int V;
int E;
vector <int> track;

template <class T>
void RESET(T* a, T b){
    for (int i = 1; i <= V; i++){
        a[i] = b;
    }
}

bool Can_go_back(int x, int y){
    a[x][y] = false;
    a[y][x] = false;
    queue <int> que;
    bool check[MAX];
    RESET(check,true);
    que.push(y);
    check[y] = false;
    while (que.empty() != true){
        int u = que.front();
        que.pop();
        for (int v = 1; v < V; v++){
            if (check[v] == true && a[u][v] == true){
                que.push(v);
                check[v] = false;
                if (check[x] == true)
                    break;
            }
        }
    }
    a[x][y] = true;
    a[y][x] = true;
    return (1 - check[x]);
}

void find_Euler_circuit(){
    int current = 1;
    int next;
    track.push_back(1);
    while (true){
        next = 0;
        for (int v = 1; v <= V; v++){
            if (a[current][v] == true){
                next = v;
                if (Can_go_back(current,next))
                    break;
            }
        }
        if (next != 0){
            a[current][next] = false;
            a[next][current] = false;
            track.push_back(next);
            current = next;
        }
        else
            break;
    }
}

void show_track(){
    for (int i = 0; i < track.size(); i++){
        cout << track[i] << ' ';
    }
    cout << endl;
}

int main() {
    cin >> V;
    cin >> E;
    while (E--){
        int u;
        int v;
        cin >> u >> v;
        a[u][v] = true;
        a[v][u] = true;
    }
    find_Euler_circuit();
    show_track();
    return 0;
}