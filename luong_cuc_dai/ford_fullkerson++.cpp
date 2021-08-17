#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <fstream>
#include <vector>
#define FOR(i,a,b) for (int i = a; i <= b; i++)

using namespace std;

const int maxV = 100;
const int maxE = maxV * (maxV - 1)/2;
const int maxC = 101;
const string output = "MaxFlow.OUP";
const string input = "MaxFlow.INP";

//dinh 
int V;
//canh
int E;

int c[maxV][maxV];
//luong
int f[maxV][maxV];
//do thi luong gia
int cf[maxV][maxV];
//luu vet duong di
int trace[maxV];

int A;
int B;
//dinh phat va dinh thu

//prototype
void loadGraph();
void string_process_I(string);
void string_process_II(string);
void initGfgraph();
bool pindPath();
void incFlow();
void showResult();

template <class T>
void RESET(T* a,T b){
    for (int i = 1; i <= V; i++){
        a[i] = b;
    }
}

//LoadGraph

void loadGraph(){
    fstream my_input(input,ios::in);
    if (my_input.fail()){
        cerr << "file not open for reading";
        return;
    }
    string first_data;
    getline(my_input,first_data);
    string_process_I(first_data);
    for (int i = 1; i <= V; i++){
        RESET(c[i],0);
    }
    while (!my_input.eof()){
        string data;
        getline(my_input,data);
        string_process_II(data);
    }
    FOR(i,1,V){
        RESET(f[i],0);
    }
    my_input.close();
}

void string_process_I(string unknown){
    int space = 0;
    string cmp = "";
    unknown += ' ';
    for (int i = 0; i < unknown.length(); i++){
        if (unknown[i] == ' '){
            if (space == 0){
                V = stoi(cmp);
                space = 1;
            }
            else if (space == 1){
                E = stoi(cmp);
                space = 2;
            }
            else if (space == 2){
                A = stoi(cmp);
                space = 3;
            }
            else {
                B = stoi(cmp);
            }
            cmp = "";
            continue;
        }
        cmp += unknown[i];
    }
}

void string_process_II(string unknown){
    int space = 0;
    string cmp = "";
    unknown += ' ';
    int u,v;
    for (int i = 0; i < unknown.length(); i++){
        if (unknown[i] == ' '){
            if (space == 0){
                u = stoi(cmp);
                space = 1;
            }
            else if (space == 1){
                v = stoi(cmp);
                space = 2;
            }
            else {
                c[u][v] = stoi(cmp);
                space = 3;
            }
            cmp = "";
            continue;
        }
        cmp += unknown[i];
    }
};

//Init 
void initGfgraph(){
    FOR(i,1,V){
        RESET(cf[i],maxC);
    }
    FOR(u,1,V){
        FOR(v,1,V){
            if (c[u][v] > f[u][v]){
                cf[u][v] = c[u][v] - f[u][v];
            }
            if (f[u][v] > 0){
                cf[v][u] = -f[u][v];
            }
        }
    }
}

bool findPath(){
    queue <int> que;
    bool Free[maxV];
    RESET(Free,true);
    Free[A] = false;
    que.push(A);
    while (que.size()){
        int u = que.front();
        que.pop();
        FOR(v,1,V){
            if (Free[v] == true && cf[u][v] != maxC){
                trace[v] = u;
                if (v == B){
                    return true;
                }
                Free[v] = false;
                que.push(v);
            }
        }
    }
    return false;
}

void incFlow(){
    //tim dinh co trong so nho nhat
    int min = INT_MAX;
    int v = B;
    while (v != A){
        int u = trace[v];
        if (abs(cf[u][v]) < min){
            min = abs(cf[u][v]);
        }
        v = u;
    }
    v = B;
    while (v != A){
        int u = trace[v];
        if (cf[u][v] <= 0){
            f[v][u] = f[v][u] - min;
        } 
        else {
            f[u][v] = f[u][v] + min;
        }
        v = u;
    }
}

void showResult(){
    fstream my_output(output,ios::out);
    my_output << "Flow" << endl;
    int m = 0;
    FOR(u,1,V){
        FOR(v,1,V){
            if (c[u][v] > 0){
                my_output << "f("<<u<<","<<v<<"): " << f[u][v] << endl;
                if (u == A){
                    m = m + f[u][v];
                }
            }
        }
    }
    my_output << "MaxFlow: " << m << endl;
    my_output.close();
}

int main() {
    loadGraph();
    while (true){
        initGfgraph();
        if (!findPath()){
            break;
        }
        incFlow();
    }
    showResult();
    return 0;
}