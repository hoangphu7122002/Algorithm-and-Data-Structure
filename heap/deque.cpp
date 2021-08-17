#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

//them mot phan tu lien quan den min-max: xai hang doi hai dau
int solve(vector<int>&arr,int k){
    int n = arr.size();
    int* d = new int[n + 1];
    d[0] = 0;
    int res = 0;
    for (int i = 1; i <= n; ++i){
        d[i] = INT_MAX;
    }
    int min_ = INT_MAX;
    deque <int> dq;
    dq.push_back(0);
    for (int i = 1; i <= n; i++){
        res += arr[i - 1];

        while (dq.size() && dq.front() < i - k){
            dq.pop_front();
        }

        d[i] = d[dq.front()] + arr[i - 1];

        while (dq.size() && d[i] < d[dq.back()]){
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= n - k + 1 && min_ > d[i]){
            min_ = d[i];
        }
        cout << d[i] << endl;
    }
    return (res - min_);
}

int main(){
    vector <int> arr{1,4,2,3,6,5,9};
    cout << solve(arr,3);
    return 0;
}