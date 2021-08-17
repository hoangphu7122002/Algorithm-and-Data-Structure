#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>


using namespace std;
//const
const string inputFile = "ASSIGN.INP";
const string outputFile = "ASSIGN.OUP";
const int maxV = 100;
const int maxC = 10001;
//variable
int V_X;
int V_Y;
int MAX;
//array and matrix
int c[maxV][maxV];
int Fx[maxV],Fy[maxV];
int matchX[maxV],matchY[maxV];
int trace[maxV];
int arg[maxV]; //dinh nhan cay pha
int start, finish;
queue <int> que;
//ki thuat thuat toan Prim
int d[maxV];
//prototype
void loadGraph();
void init();
void initBFS();
void pindPath();
void enLarge();
void solve();
void showResult();

template <class T>
void RESET(T* a,T b, int size = maxV){
    for (int i = 1; i <= size; i++){
        a[i] = b;
    }
}

vector <int> tokenize (string s,string del = " "){
    vector <int> res;

    int begin = 0;
    int end = s.find(del);
    while (end != -1){
        res.push_back(stoi(s.substr(begin,end - begin)));
        begin = end + (int)del.size();
        end = s.find(del,begin);
    }
    res.push_back(stoi(s.substr(begin,end-begin)));
    return res;
}

void loadGraph(){
    fstream my_input(inputFile,ios::in);

    if (my_input.fail()){
        cerr << "the file not open for reading";
        return;
    }

    string first_data;
    getline(my_input,first_data);
    vector <int> info = tokenize(first_data);
    V_X = info[0];
    V_Y = info[1];
    MAX = max(V_X,V_Y);

    for (int i = 1; i <= MAX; i++){
        RESET(c[i],maxC);
    }

    while (!my_input.eof()){
        string data;
        getline(my_input,data);
        vector <int> cmd = tokenize(data);
        c[cmd[0]][cmd[1]] = cmd[2];
    }

    my_input.close();
}

void init(){
    RESET(matchX,0,V_X);
    RESET(matchY,0,V_Y);
    for (int i = 1; i <= MAX; i++){
        Fx[i] = maxC;
        for (int j = 1; j <= MAX; j++){
            if (c[i][j] < Fx[i]){
                Fx[i] = c[i][j];
            }
        }
    }
    for (int j = 1; j <= MAX; j++){
        Fy[j] = maxC;
        for (int i = 1; i <= MAX; i++){
            if (c[i][j] - Fx[i] < Fy[j])
                Fy[j] = c[i][j] - Fx[i];
        }
    }
}

//canh gia
int getC(int i,int j){
    return c[i][j] - Fx[i] - Fy[j];
}

//khoi tao cay tim kiem 
void initBFS(){
    RESET(trace,0);
    que.push(start);
    for (int y = 1; y <= MAX; y++){
        d[y] = getC(start,y);
        arg[y] = start;
    }
    finish = 0;
}

void findPath(){
    //canh y tham qua canh x
    while (que.size()){
        int i = que.front();
        que.pop();
        for (int j = 1; j <= V_Y; j++ ){
            if (trace[j] == 0){
                int w = getC(i,j);
                if (w == 0){
                    trace[j] = i;
                    if (matchY[j] == 0){
                        finish = j;
                        return;
                    }
                    que.push(matchY[j]);
                }
                if (d[j] > w){
                    //nhung dinh d[j] luu lai trong so nho nhat tren duong tu start toi j
                    d[j] = w;
                    //tham hay chua tham gi cung phai luu goc truoc da
                    //luu goc tim kiem
                    arg[j] = i;
                }
            }
        }
    }
}

void subX_addY(){
    int Delta = maxC;
    for (int y = 1; y <= V_Y; y++){
        //khong thuoc cay va chua tham
        if (trace[y] == 0 && d[y] < Delta)
            Delta = d[y];
    }
    Fx[start] += Delta;
    for (int y = 1; y <= V_Y; y++){
        if (trace[y] != 0){
            int x = matchY[y];
            Fy[y] -= Delta;
            Fx[x] += Delta;
        }
        else {
            d[y] -= Delta;
        }
    }
    for (int y = 1; y <= V_Y; y++){
        if (trace[y] == 0 && d[y] == 0){
            trace[y] = arg[y];
            if (matchY[y] == 0){
                finish = y;
                return;
            }
            que.push(matchY[y]);
        }
    }
}

void enLarge(){
    int x;
    int next;
    while (finish != 0){
        x = trace[finish];
        next = matchX[x];
        matchX[x] = finish;
        matchY[finish] = x;
        finish = next;
    }
}

void solve(){
    int x;
    for (x = 1; x <= V_X; x++){
        start = x;
        initBFS();
        while (true){
            findPath();
            if (finish != 0){
                break;
            }
            subX_addY();
        }
        enLarge();
    }
}

void printResult(){
    fstream my_output(outputFile,ios::out);

    if (my_output.fail()){
        cerr << "the file haven't permision for writing";
        return;
    }

    int count = 0;
    int min = 0;
    for (int x = 1; x <= V_X; x++){
        int y = matchX[x];
        if (c[x][y] < maxC){
            my_output << "X["<<x<<"] - Y["<<y<<"]: " << c[x][y] << endl;
            count++;
            min += c[x][y];
        }
    }

    my_output << "Cost Min: " << min << endl;
    my_output.close();
}

int main(){
    loadGraph();
    init();
    solve();
    printResult();
    return 0;
}
