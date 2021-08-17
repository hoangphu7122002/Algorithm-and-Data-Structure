//thuat toan warshall
#include <iostream>
#include <vector>

using namespace std;

int n;
int m;
bool a[712][712]{};
bool check[712]{};

void Warshall(){
    for (int u = 1; u <= n; u++) {
        for (int k = 1; k <= n; k++){
            if (a[u][k] == true)
                for (int v = 1; v <= n; v++){
                    if (a[k][v] == true)
                        a[u][v] = true; 
                }
        }
    }
}

void dem_lien_thong(){
    int dem = 0;
    for (int u = 1; u <= n; u++){
        if (check[u] == false){
            dem++;
            for (int v = 1; v <= n; v++){
                if (a[u][v] == true){
                    check[v] = false;
                }
            }
        }
    }
}

 

int main() {
    cin >> n;
    cin >> m;
    while (m--){
        int u;
        int v;
        cin >> u >> v;
        a[u][v] = true;
        a[v][u] = true;
    }
    return 0;
}