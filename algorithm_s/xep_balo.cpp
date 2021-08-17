#include <iostream>
using namespace std;

const int Max = 20;
int W[21];
int V[21];
int n;
int M;
bool check[21]{};
bool saveCheck[21]{};

int vMax;
int weight;
int value;

void input(){
    cin >> n;
    cin >> M;
    for (int i = 1; i <= n; i++){
        cin >> W[i] >> V[i];
    }
}

void init(){
    vMax = -1;
    weight = 0;
    value = 0;   
}

void keepResult(){

}

void Try(int i){
    check[i] = true;
    weight = weight + W[i];
    value = value + V[i];
    if (weight <= M){
        if (i == n){
            keepResult();
        }   
        else
            Try(i + 1);
    }
    check[i] = false;
    weight = weight - W[i];
}

int main() {

    return 0;
}