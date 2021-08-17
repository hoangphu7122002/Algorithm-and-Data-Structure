#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 100;

vector<int> a[7120];
int path[7120]{};

void BFS(int u){
    path[u] = 1;
    queue <int> que;
    que.push(u);
    int temp;
    while (que.empty() == false){
        temp = que.front();
        que.pop();
        cout << temp << ' ';
        for (int i = 0; i < a[temp].size(); i++){
            int v = a[temp][i];
            if (path[v] == 0){
                que.push(v);
                path[v] = path[temp] + 1;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    while (m--){
        int u;
        int v;
        cin >> u;
        cin >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    BFS(1);
    cout << endl;
    for (int i = 2; i <= 5; i++){
        cout << path[i] << ' ';
    }
}