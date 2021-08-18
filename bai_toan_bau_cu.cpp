#include <iostream>
#include <vector>

using namespace std;

//time O(n) && space O(1)

//----------------------------------------------------------------
//two people is electied

int majorityElement(vector<int>& nums) {
        int vote = 0;
        int candidate;
        for (auto& num : nums){
            if (candidate == num){
                vote++;
            }
            else if (vote == 0){
                candidate = num;
                vote = 1;
            }
            else {
                vote -= 1;
            }
        }
        return candidate;
    }
    
//----------------------------------------------------------------
//3 people is electied
vector<int> majorityElement_plus(vector<int>& nums) {
        int candidate1 = -1;
        int candidate2 = -1;
        int sum1 = 0;
        int sum2 = 0;
        int n = nums.size();
        for (auto& num : nums){
            if (num == candidate1){
                sum1++;
            }
            else if (num == candidate2){
                sum2++;
            }
            else if (sum1 == 0){
                candidate1 = num;
                sum1 = 1;
            }
            else if (sum2 == 0){
                candidate2 = num;
                sum2 = 1;
            }
            else {
                sum1 -= 1;
                sum2 -= 1;
            }
        }
        sum1 = 0;
        sum2 = 0;
        if (candidate1 == candidate2)
            return {candidate1};
        for (auto& num : nums){
            if (num == candidate1) 
                sum1++;
            if (num == candidate2)
                sum2++;
        }
        vector <int> res;
        if (sum1 > n/3){
            res.push_back(candidate1);
        }
        if (sum2 > n/3){
            res.push_back(candidate2);
        }
        return res;
}

