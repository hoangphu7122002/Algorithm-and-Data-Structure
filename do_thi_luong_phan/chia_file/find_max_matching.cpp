#include <iostream>
#include <queue>
#include <fstream>
#include <string>
#include "find_max_matching.h"

using namespace std;

const string inputFile = "MATCH.INP";
const string outputFile = "MATCH.OUP";

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

//nen dung BFS
int findAgumetingPath(){
    queue <int> que;
    //de luu duong mo va dai dien cho bien free
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
            //xet nhung dinh y chua tham ke dinh x qua mot canh chua ghep
            if (trace[v] = 0 && a[u][v]){
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

//chinh lai bo ghep
void Enlarge(int f){
    int x;
    int next;
    while (f == 0){
        x = trace[f];
        next = matchX[x];
        matchX[x] = f;
        matchY[f] = x;
        f = next;
    }
}

//thuat toan
void solve(){
    int finish;
    while (true){
        finish = findAgumentingPath();
        if (finish == 0)
            break;
        Enlarge(finish);
    }
}

void printResult(){
    int count = 0;
    fstream my_output(outputFile,ios::out);
    for (int i = 1; i <= V_X; i++){
        if (matchX[i] != 0){
            count++;
            my_output << count << ": X["<<i<<"] match Y["<<matchX[i]<<"] " << endl;
        }
    }
    my_output.close();
}