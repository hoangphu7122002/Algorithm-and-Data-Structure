#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <string>

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
//bien dung de tao nhan tim canh co trong so nho nhat 
int Delta[maxV];
//delta(v) la gia tri nho nhat cua trong so cua 1 canh tu A den v

int A;
int B;
//dinh phat va dinh thu

//prototype
void loadGraph();
void string_process_I(string);
void string_process_II(string);
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
    for (int i = 1; i <= V; i++){
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

//khong tao do thi Gf, tan dung bien trace
//dung BFS it lan lap hon DFS
bool findPath(){
    //ung dung nhu bien Free
    RESET(trace,0);
    queue <int> que;
    trace[A] = maxC;
    que.push(A);
    Delta[A] = maxC;
    while (que.size()){
        int u = que.front();
        que.pop();
        for (int v = 1; v <= V; v++){
            //neu chua danh dau va day la do thi gia nen khong can truong hop c[u][v] > 0
            if (trace[v] == 0){
                if (c[u][v] > f[u][v]){
                    trace[v] = u;
                    Delta[v] = min(Delta[u],c[u][v] - f[u][v]);
                }
                else if (f[v][u] > 0){
                    trace[v] = -u;
                    Delta[v] = min(Delta[u],f[v][u]);
                }
                if (trace[v] != 0){
                    if (v == B){
                        return true;
                    }
                    que.push(v);
                }
            }
        }
    }
    return false;
}

void incFlow(){
    int min = Delta[B];
    int v = B;
    while (v != A){
        int u = trace[v];
        if (u > 0){
            f[u][v] += min;
        }
        else {
            u = -u;
            f[v][u] -= min;
        }
        v = u;
    }
}

void showResult(){
    fstream my_output(output,ios::out);
    my_output << "Flow" << endl;
    int m = 0;
    for (int u = 1; u <= V; u++){
        for (int v = 1; v <= V; v++){
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
        if (!findPath()){
            break;
        }
        incFlow();
    }
    showResult();
    return 0;
}