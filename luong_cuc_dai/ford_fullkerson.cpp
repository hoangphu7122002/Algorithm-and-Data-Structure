#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <fstream>  
#include <string> 
#include <cmath>

using namespace std;

const int MaxV = 100;
const int MaxM = MaxV * (MaxV - 1)/2;
int n;
int m;
int c[MaxV][MaxV];
int f[MaxV][MaxV];
//day la do thi tang luong
int cf[MaxV][MaxV];
int Trace[MaxV];
int A;
int B;
const int MaxC = 101;

//filename
string InputFile = "MaxFlow.INP";
string OutputFile = "MaxFlow.OUP";

//prototype
void LoadGraph();
void CreateGf();
bool findPath();
void IncFlow();
void printResult();

template <class T>
void RESET(T* a, T b){
    for (int i = 1; i <= n; i++)
        a[i] = b;
}

void LoadGraph(){
    for (int i = 1; i <= n; i++){
        RESET(f[i],0);
    }
    fstream inf(InputFile,ios::in);
    if (inf.fail()){
        cerr << "can not open for reading";
        return;
    }
    string b_strInput;
    getline(inf,b_strInput);
    b_strInput += ' ';
    int space = 0;
    string cmp = "";
    for (int i = 0; i < b_strInput.length(); i++){
        if (b_strInput[i] == ' '){
            if (space == 0){
                space = 1;
                n = stoi(cmp);
            }
            else if (space == 1){
                space = 2;
                m = stoi(cmp);
            }
            else if (space == 2){
                space = 3;
                A = stoi(cmp);
            }
            else {
                B = stoi(cmp);
            }
            cmp = "";
            continue;
        }
        cmp += b_strInput[i];
    }
    for (int i = 1; i <= n; i++){
        RESET(c[i],0);
    }
    // int index = 0;
    while (!inf.eof()){
        cmp = "";
        space = 0;
        string strInput;
        getline(inf,strInput);
        int u; int v;
        strInput += ' ';
        for (int i = 0; i < strInput.length(); i++){
            if (strInput[i] == ' '){
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
                }
                cmp = "";
                continue;
            }
            cmp += strInput[i];
        }       
    }
    inf.close();
}

void CreateGf(){
    //cf la do thi giam
    for (int u = 1; u <= n; u++){
        for (int v = 1; v <= n; v++){
            cf[u][v] = MaxC;
        }
    }
    for (int u = 1; u <= n; u++){
        for (int v = 1; v <= n; v++){
            if (c[u][v] > 0){
                if (f[u][v] < c[u][v]){
                    cf[u][v] = c[u][v] - f[u][v]; //cung thuan
                }
                if (f[u][v] > 0)
                    cf[v][u] = -f[u][v];
            }
        }
    }
}

//dung BFS do nhu cau can nhieu duong
bool findPath(){
    int dem = 0;
    queue <int> que;
    bool Free[MaxV];
    RESET(Free,true);
    que.push(A);
    Free[A] = false;
    while (!que.empty()){
        int u = que.front();
        que.pop();
        for (int v = 1; v <= n; v++){
            if (Free[v] == true && cf[u][v] != MaxC){
                Trace[v] = u;
                if (v == B){
                    return true;
                }
                Free[v] = false;
                que.push(v);
            }
        }
    }
    cout << "xyz" << endl;
    return false;
}

void IncFlow(){
    int u;
    int v = B;
    int incValue = MaxC;
    //do duong de tim trong so nho nhat
    while (v != A){
        u = Trace[v];
        if (abs(cf[u][v]) < incValue){
            incValue = abs(cf[u][v]);
        }
        v = u;
    }
    v = B;
    //do duong lan 2 de tang luong
    while (v != A){
        u = Trace[v];
        if (cf[u][v] > 0)
            f[u][v] += incValue;
        else 
            f[v][u] = f[v][u] - incValue;
        v = u;
    }
}

void PrintResult(){
    fstream output(OutputFile,ios::out);
    if (output.fail()){
        cerr << "can not open for reading";
        return;
    }
    m = 0;
    for (int u = 1; u <= n; u++){
        for (int v  = 1; v <= n; v++){
            if (c[u][v] > 0){
                output << "f("<<u<<" , "<<v<<") : " << f[u][v] << endl;
                if (u == A){
                    m = m + f[u][v];
                }
            }
        }
    }
    output << "Max_flow: " << m << endl;
    output.close();
}

int main() {
    LoadGraph();
    while (true){
        CreateGf();
        if (findPath() == false){
            break;
        }
        IncFlow();

    }
    PrintResult();
    return 0;
}