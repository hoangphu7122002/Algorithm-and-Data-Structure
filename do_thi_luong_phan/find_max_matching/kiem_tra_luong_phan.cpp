#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int maxV = 100;
const int maxE = maxV * (maxV - 1)/2;
const int maxC = maxV + 1;

int Visited[maxV];
vector <int> a[maxV];

int V;
int E;

template<class T>
void RESET(T* a,T b){
    for (int i = 1; i <= maxV; i++){
        a[i] = b;
    }
}

void loadGraph(){
    cin >> V >> E;
    RESET(Visited,0);
    for (int i = 1; i <= E; i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

//Ung dung BFS
bool isBipartite(){
    if (E == 1)
        return true;
    queue <int> que;
    for (int i = 1; i <= V; i++){
        if (Visited[i] == 0){
            Visited[i] = 1;
            que.push(i);
            while (que.size()){
                int u = que.front();
                for (int v: a[u]){
                    if (Visited[v] == 0){
                        Visited[v] = 3 - Visited[u];
                        que.push(v);        
                    }
                    else {
                        if (Visited[v] == Visited[u])
                            return false;
                    }
                }
            }
        }
    }
    return true;
}

int main(){
    return 0;
}