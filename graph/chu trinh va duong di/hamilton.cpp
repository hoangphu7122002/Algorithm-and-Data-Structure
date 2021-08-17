#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100;
bool a[MAX][MAX];
int V;
int E;
int track[MAX];
bool Free[MAX];

template <class T>
void RESET(T* a, T b){
    for (int i = 1; i <= V; i++){
        a[i] = b;
    }
}

void Try(int i){
    for (int j = 1; j <= V; j++){
        if (Free[j] == true && a[track[i - 1]][j] == true){
            track[i] = j;
            if (i < V){
                Free[j] = false;
                Try(i + 1);
                Free[j] = true;
            }    
            else {
                if (a[j][track[1]] == true){
                   for (int k = 1; k <= V; k++){
                       cout << track[k] << ' ';
                   }
                   cout << endl;
                   return;
                }
            }
        }
    }
}

int main() {
    cin >> V;
    cin >> E;
    for (int i = 1; i <= V; i++){
        RESET(a[i],false);
    }
    RESET(Free,true);
    while (E--){
        int u,v;
        cin >> u >> v;
        a[u][v] = true;
        a[v][u] = true;
    }
    track[1] = 1;
    Free[1] = false;
    Try(2);
    return 0;
}