#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

const int maxV = 100;
const int maxE = (maxV - 1) *  maxV / 2;

//O(mlogm)

//cay khung lien quan danh sach canh
struct Edge{
    int u;
    int v;
    int c;
    bool Mark;
    Edge operator = (const Edge& T){
        this->u = T.u;
        this->v = T.v;
        this->c = T.c;
        this->Mark = T.Mark;
    }
};

//danh sach canh
Edge E[maxE];
int Lab[maxV]; //lab[v] la dinh goc V
int n;
int m;
bool connected;

//Prototype
void LoadGraph();
void Init();
int GetRoot(int);
void Union(int,int);
void AdjustHeap(int,int);
void Kruskal();
void swap(Edge& a, Edge& b);
void show_result();

void LoadGraph(){
    cin >> n;
    cin >> m;
    for (int i = 1; i <= m; i++){
        int u,v,c;
        cin >> u >> v >> c;
        E[i].u = u;
        E[i].v = v;
        E[i].c = c;
    }
}

void Init(){
    for (int i = 1; i <= n; i++){
        Lab[i] = -1;
    }
    for (int i = 1; i <= m; i++){
        E[i].Mark = false;
    }
}

//ban dau chi co 1 nut duy nhat
int GetRoot(int v){
    while (Lab[v] > 0)
        v = Lab[v];
    return v;
}

//Lab am;
void Union(int r1, int r2){
    int x = Lab[r1] + Lab[r2];
    if (Lab[r1] > Lab[r2]){
        Lab[r1] = r2;
        Lab[r2] = x;
    }
    else {
        Lab[r1] = x;
        Lab[r2] = r1;
    }
}

//thuat toan vun dong dung cho heap sort
void AdjustHeap(int root, int last){
    Edge Key;
    while (root * 2 <= last){
        Key = E[root];
        int child = root*2;
        if (child < last && E[child + 1].c < E[child].c){
            child++;
        }
        if (Key.c <= E[child].c){
            break;
        }
        //chon goc
        E[root] = E[child];
        root = child;
    }
    E[root] = Key;
}

//thuat toan Kruskal
void Kruskal(){
    int r1;
    int r2;
    int Count = 0;
    //dem so canh
    connected = false;
    //danh dau tim duoc cay khung nho nhat
    //tu tuong heap_sort
    for (int i = m/2; i>= 1; i--){
        AdjustHeap(i,m);
    }
    for (int i = m - 1; i >= 0; i--){
        swap(E[1],E[i + 1]);
        //de lay E[1] ra xai
        AdjustHeap(1,i);
        r1 = GetRoot(E[i + 1].u);
        r2 = GetRoot(E[i + 1].v);
        if (r1 != r2){
            E[i + 1].Mark = true;
            Count++;
            if (Count == n - 1){
                connected = true;
                return;
            }
            Union(r1,r2);
        }
    }   
}

void swap(Edge& a, Edge& b){
    Edge c = a;
    a = b;
    b = c;
}

void show_result(){
    if (connected == false){
        cout << "Error: Graph is not connected" << endl;
        return;
    }
    int Count = 0;
    int Weight = 0;
    for (int i = 1; i <= m; i++){
        if (E[i].Mark == true){
            cout << "("<<E[i].u<<" -> "<<E[i].v<<") = "<<E[i].c<<"" << endl;
            Count++;
            Weight += E[i].c;
        }
        if (Count == n - 1){
            break;
        }
    }
}

 int main() {
    return 0;  
}