#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int>& a,pair<int,int>& b){
    return (a.first > b.first);
}

class Function{
private:
    vector <int> deg;
    vector <int> coeff;
public:
    Function(vector<int> deg,vector<int> coeff){
        for (int i = 0; i < deg.size(); i++){
            this->deg.push_back(deg[i]);
        }
        for (int i = 0; i < coeff.size(); i++){
            this->coeff.push_back(coeff[i]);
        }
    }
    Function() = default;
    Function& mulFunc(const Function& a,const Function& b){
        vector <pair<int,int>> v;
        //mu_lon_nhat_dung_dau
        for (int i = 0; i < a.deg.size(); i++){
            for (int j = 0; j < b.deg.size(); j++){
                v.push_back({a.deg[i] * b.deg[j],a.coeff[i] * b.coeff[j]});
            }
        }
        Function* res = new Function();
        sort(v.begin(),v.end(),compare);
        int tong = v[0].second;
        for (int i = 1; i < v.size(); i++){
            if (v[i].first == v[i - 1].first){
                tong += v[i].second;
                if (i == v.size() - 1 && tong != 0){
                    res->deg.push_back(v[i].first);
                    res->coeff.push_back(v[i].second);
                }
                continue;
            }
            if (tong == 0){
                tong = v[i].second;
                continue;
            }
            res->deg.push_back(v[i - 1].first);
            res->coeff.push_back(tong);
            tong = v[i].second;
            if (i == v.size() - 1){
                res->deg.push_back(v[i].first);
                res->coeff.push_back(tong);
            }
        }
        return *res;
    }
    void print(){
        for (int i = 0; i < deg.size(); i++){
            if (coeff[i] == 0){
                continue;
            }
            if (deg[i] == 0){
                cout << coeff[i];
            }
            else {
                if (coeff[i] != 1)
                    cout << coeff[i] << "x";
                else {
                    cout << "x";
                }
                if (deg[i] != 1){
                    cout << "^" << deg[i];
                }
            }
            if (i != deg.size() - 1){
                if (coeff[i + 1] > 0){
                    cout << "+";
                }
            }
        }
    }
};

int main(){
    
    return 0;
}