#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solve(vector<int>&arr,int k){
    int n = arr.size();
    int* d = new int[n + 1];
    d[0] = 0;
    int res = 0;
    for (int i = 1; i <= n; ++i){
        d[i] = INT_MAX;
    }
    int min_ = INT_MAX;
    for (int i = 1; i <= n; ++i){
        res += arr[i - 1];
        for (int j = max(0,i - k); j <= i - 1; ++j)
            d[i] = min(d[i],d[j] + arr[i - 1]);
        if (i >= n - k + 1 && min_ > d[i]){
            min_ = d[i];
        }
    }
    for (int i = 0; i < n; i++){
        cout << arr[i] << ' ' << d[i + 1] << endl;
    }
    return (res - min_);
}



int main(){
    vector <int> arr{1,4,2,3,6,5,9};
    cout << solve(arr,3);
    return 0;
}