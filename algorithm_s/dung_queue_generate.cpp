#include <iostream>
#include <queue> 
#include <cmath>
using namespace std;

int main() {
    queue <string> que;
    que.push("0");
    que.push("1");
    int n;
    cin >> n;
    while (que.size() < pow(2,n)){
        que.push(que.front() + '0');
        que.push(que.front() + '1');
        que.pop();
    } 
    while (que.empty() == false){
        cout << que.front() << endl;
        que.pop();
    }
    return 0;
}