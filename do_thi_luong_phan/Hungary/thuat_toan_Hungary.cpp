#include <iostream>
#include <algorithm>
#include <queue>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

const string inputFile = "ASSIGN.INP";
const string outputFile = "ASSIGN.OUP";
const int maxV = 100;
const int maxC = 101;
//khong lien quan toi canh

//variable
int V_X;
int V_Y;
int start;
int finish;
//bien luu tru kich thuoc toi da
int MAX; 
//ma tran trong so
int c[maxV][maxV];
int Fx[maxV];
int Fy[maxV];
int matchX[maxV];
int matchY[maxV];
int trace[maxV];

//prototype
vector<int> tokenize(string,string);
void loadGraph();
void init();
void findPath();
void subX_AddY();
void enLarge();
void solve();
void showResult();

template <class T>
void RESET(T* a,T b,int size){
    for (int i = 1; i <= size; i++){
        a[i] = b;
    }
}

vector <int> tokenize(string data,string del = " "){
    vector<int>res;
    int begin = 0;
    int end = (int)data.find(del);
    while (end != -1){
        //end - begin bang so phan tu
        res.push_back(stoi(data.substr(begin,end - begin)));
        begin = end + (int)del.size();
        end = data.find(del,begin);
    }
    res.push_back(stoi(data.substr(begin,end-begin)));
    return res;
}

void loadGraph(){
    fstream my_input(inputFile,ios::in);

    if(my_input.fail()){
        cerr << "don't find the existence of file";
        return;
    }

    string first_data;
    getline(my_input,first_data);
    vector <int> info = tokenize(first_data);

    V_X = info[0];
    V_Y = info[1];
    MAX = max(V_X,V_Y);

    cout << V_X <<  ' ' << V_Y << endl;

    for (int i = 1; i <= MAX; i++){
        RESET(c[i],maxC,MAX);
    }

    while (!my_input.eof()){
        string data;
        getline(my_input,data);  
        if (data == "") continue;
        vector <int> cmd = tokenize(data);
        c[cmd[0]][cmd[1]] = cmd[2];
    }


    //Debug
    for (int i = 1; i <= MAX; i++) {
        for (int j = 1; j <= MAX; j++){
            cout << c[i][j] << ' ';
        }
        cout << endl;
    }

    my_input.close();
}

void init(){
    RESET(matchX,0,V_X);
    RESET(matchY,0,V_Y);
    for (int i = 1; i <= MAX; i++){
        Fx[i] = maxC;
        for (int j = 1; j <= MAX; j++){
            if (c[i][j] < Fx[i])
                Fx[i] = c[i][j];           
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

int getC(int i,int j){
    return c[i][j] - Fx[i] - Fy[j];
}

void findPath(){
    RESET(trace,0,MAX);
    queue <int> que;
    que.push(start);
    while (que.size()){
        int u = que.front();
        que.pop();
        for (int v = 1; v <= V_Y; v++){
            //tham nhung dinh chua tham va la khong canh
            if (trace[v] == 0 && getC(u,v) == 0){
                trace[v] = u;
                if (matchY[v] == 0){
                    finish = v;
                    return;
                }
                que.push(matchY[v]);
            }
        }
    }
    return;
}

void subX_AddY(){
    map <int,int> visitX{};
    map <int,int> visitY{};
    visitX[start] = 1;
    for (int i = 1; i <= V_Y; i++){
        if (trace[i] != 0){
            visitY[i] = 1;
            visitX[matchY[i]] = 1;
        }
    }
    int Delta = maxC;
    for (int i = 1; i <= V_X; i++){
        if (visitX[i] == 1){
            for (int j = 1; j <= V_Y; j++){
                if (visitY[j] == 0 && getC(i,j) < Delta)
                    Delta = getC(i,j);
            }
        }
    }
    for (int i = 1; i <= MAX; i++){
        if (visitX[i] == 1)
            Fx[i] += Delta;
        if (visitY[i] == 1)
            Fy[i] -= Delta;
    }
}

void enLarge(){
    int x;
    int next;
    //dinh dau tien luon co trace v bang 0
    while (finish != 0){
        x = trace[finish];
        next = matchX[x];
        matchY[finish] = x;
        matchX[x] = finish;
        finish = next;
    }
}

void solve(){
    //O(n^3)
    for (int x = 1; x <= MAX; x++){
        finish = 0;
        start = x;
        //tim tat ca duong mo cho den khi khong con thay nưa
        while (true){
            findPath();
            subX_AddY();
            if (finish != 0){
                break;
            }            
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










