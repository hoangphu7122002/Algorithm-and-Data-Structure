#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <fstream>

using namespace std;

//const
const string inputFile = "MATCH.INP";
const string outputFile = "MATCH.OUP";
const int maxV = 100;
const int maxE = maxV * (maxV - 1)/2;
const int maxC = 101;

//variable

//bien dinh, cap ghep
int V_X;
int V_Y;

//bieu dien bo ghep
bool a[maxV][maxV];
//bieu dien cap ghep
int matchX[maxV];
int matchY[maxV];
//bieu dien vet duong di va kiem tra xem dinh do co tham chua
int trace[maxV];


//prototype
//Load graph
void process_string_I(string);
void process_string_II(string);
void loadGraph();

//algorithm
void init();
int pindPath();
void enLarge(int f);
void algorithm();
void printResult();

template <class T>
void RESET(T* a,T b,int size){
    for (int i = 1; i <= size; i++){
        a[i] = b;
    }
}

void process_string_I(string data){
    data += ' ';
    bool flip = false;
    string cmp = "";
    for (int i = 0; i < data.length(); i++){
        if (data[i] == ' '){
            if (flip == false){
                V_X = stoi(cmp);
                flip = true;
            }
            else {
                V_Y = stoi(cmp);
            }
            cmp = "";
            continue;
        }
        cmp += data[i];
    }
}

void process_string_II(string data){
    data += ' ';
    int increase = 0;
    string cmp = "";
    int u,v;
    for (int i = 0; i < data.length(); i++){
        if (data[i] == ' '){
            if (increase == 0){
                u = stoi(cmp);
                ++increase;
            }
            else if (increase == 1){
                v = stoi(cmp);
                ++increase;
            }
            else {
                a[u][v] = true;
            }
            cmp = "";
            continue;
        }
        cmp += data[i];
    }
}

void loadGraph(){
    fstream my_input(inputFile,ios::in);

    if (!my_input){
        cerr << "The file is not open for reading";
        return;
    }

    for (int i = 1; i <= maxV; i++)
        RESET(a[i],true,maxV);

    string first_data;
    getline(my_input,first_data);
    process_string_I(first_data);

    while (!my_input.eof()){
        string data;
        getline(my_input,data);
        process_string_II(data);
    }

    my_input.close();
}

void init(){
    RESET(matchX,0,V_X);
    RESET(matchY,0,V_Y);
}

int pindPath(){
    //chi push nhung dinh thuoc nua X
    //BFS di theo duong mo
    queue<int>que;
    RESET(trace,0,maxV);
    for (int i = 1; i <= V_X; i++){
        if (matchX[i] == 0){
            que.push(i);
        }
    }
    while (que.size()){
        int u = que.front();
        que.pop();
        for (int v = 1; v <= V_Y; v++){
            if (trace[v] == 0 && a[u][v]){
                trace[v] = u;
                if (matchY[v] == 0){
                    return v;
                }
                que.push(matchY[v]);
            }
        }
    }
    return 0;
}

void enLarge(int f){
    //f la dinh ket thuc o Y
    int x;
    int next;
    while (f != 0){
        x = trace[f];
        next = matchX[x];
        matchX[x] = f;
        matchY[f] = x;
        f = next;
    }   
}

void algorithm(){
    int finish;
    while(true){
        finish = pindPath();
        if (finish == 0)    break;
        enLarge(finish);
    }
}

void printResult(){
    //dua theo matchX, matchY
    fstream my_output(outputFile,ios::out);
    int count = 0;
    for (int i = 1; i <= V_X; i++){
        if (matchX[i] != 0){
            ++count;
            my_output << "X["<<i<<"],Y["<<matchX[i]<<"]" << endl;
        }
    }
    my_output << "Number_pair: " << count;
    my_output.close();
}

int main() {
    loadGraph();
    init();
    pindPath();
    algorithm();;
    printResult();
    return 0;
}