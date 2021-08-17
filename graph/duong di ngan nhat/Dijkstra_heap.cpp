#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100;
const int oo = 9999;
typedef pair<int,int> ii;
vector <ii> a[MAX];
int V;
int E;
int d[MAX];
int track[MAX];

void dijkstra(int k){
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    //dung de so sanh cac d[i]
    for (int i = 1; i <= V; i++){
        d[i] = oo;
    }
    d[k] = 0;
    pq.push({0,k});
    while (pq.size()){
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        //kiem tra xem dinh nay co cap nhat chua
        if (du != d[u]) continue;
        for (auto i:a[u]){
            int v = i.second;
            int uv = i.first;
            if (d[v] > d[u] + uv){
                d[v] = d[u] + uv;
                pq.push({d[v],v});
                track[v] = u;
            }
        }
    }
}

int main() {
    cin >> V;
    cin >> E;
    while (E--){
        int u,v,w;
        cin >> u >> v >> w;
        a[u].push_back({w,v});
        a[v].push_back({w,u});
    }
    dijkstra(1);
    for (int i = 1; i <= V; i++){
        cout << "1 -> " << i << " is:" << d[i] << endl;
    }
    return 0;
}