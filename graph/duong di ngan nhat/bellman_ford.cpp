#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <typeinfo>
#include <algorithm>
#define oo 9999

using namespace std;

const int MAX = 100;
int a[MAX][MAX];
int V;
int E;
int S; //start
int F; //finish
int track[MAX];
int d[MAX];
bool flag = false;

template<class T>
void RESET(T* a,T b){
    for (int i = 1; i <= V; i++){
        a[i] = b;    
    }    
}

void assign(int (*a)[MAX]){
    for (int u = 1; u <= V; u++){
        for (int v = 1; v <= V; v++){
            if (u == v)
                a[u][v] = 0;
            else 
                a[u][v] = oo;
        }
    }
}

void INIT(){
    for (int i = 1; i <= V; i++)
        d[i] = oo;
    d[S] = 0;
}

void Ford_Bellman(){
    bool stop;
    for (int i = 1; i <= V - 1; i++){
        stop = true;
        for(int v = 1; v <= V; v++){
            for (int u = 1; u <= V; u++){
                if (a[u][v] < oo){
                    if (d[v] > d[u] + a[u][v]){
                        d[v] = d[u] + a[u][v];
                        track[v] = u; //phuc vu quay lui
                        stop = false; //kiem tra nhan co thay doi duoc hay khong
                    }
                }
            }
        }
        if (stop == true)
            break;
    }
    for (int v = 1; v <= V; v++){
        for (int u = 1; u <= V; u++){
            if (a[u][v] < oo){
                if (d[v] > d[u] + a[u][v]){
                    flag = true;
                    break;
                }
            }
        }
        if (flag == true)
            break;
    }
}

void show(){
    if (flag == false){
        if (d[F] == oo){
            cout << "no sol" << endl;
        }
        else {
           cout << "distance: " << d[F] << endl;
           while (F != S){
               cout << F << "<-";
               F = track[F];
           }
           cout << S;
        }
    }
    else {
        cout << "do thi co chu trinh am" << endl;
    }
}


int main(){
    cin >> V;
    cin >> E;
    cin >> S;
    cin >> F;
    assign(a);
    while (E--){
        int u, v;
        cin >> u >> v;
        int trong_so;
        cin >> trong_so;
        a[u][v] = trong_so;
    }
    INIT();
    Ford_Bellman();
    show();
    return 0;    
}