#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define pii pair<int,int>

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        unordered_map <pii,bool> free;
        vector <pii> stores;
        for (int i = 0; i < buildings.size(); ++i){
            stores.push_back({buildings[i][0],buildings[i][2]});
            stores.push_back({buildings[i][1],buildings[i][2]});
            free[{buildings[i][0],buildings[i][2]}] = true;
            free[{buildings[i][1],buildings[i][2]}] = true;
        } 
        sort(stores.begin(),stores.end(),[](pii &a,pii &b){return (a.first > b.first);});
        vector<vector<int>>res;
        res.push_back(stores[0]);
    }
};