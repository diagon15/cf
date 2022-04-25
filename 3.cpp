#include <bits/stdc++.h>
using namespace std;

#define ll long long

template <class T>
class SparseTable {
    vector<T> data;
    vector<vector<T>> spt;
    int LOG = 0;
    vector<int>log_val;

    public:
    SparseTable(){}

    void init(vector<T> &arr){
        // SparseTable(vector<T> &arr){
        data = arr;
        int n = arr.size();
        while((1 << LOG) <= n) ++ LOG;
        spt = vector<vector<T>>(n, vector<T>(LOG));
        log_val.resize(n + 1);

        log_val[1] = 0;
        for(int i = 2; i <= n; ++ i) log_val[i] = log_val[i/2] + 1;

        for(int i = 0; i < n; ++ i){
            spt[i][0] = arr[i];
        }

        for(int l = 1; l < LOG; ++ l){
            for(int i = 0; i + (1<<l) - 1 < n; ++ i){
                spt[i][l] = min(spt[i][l - 1], spt[i + (1 << (l - 1))][l - 1]);
            }
        }
    }

    T query(int l,int r){
        int lg = log_val[r - l + 1];

        return min(spt[l][lg], spt[r - (1<<lg) + 1][lg]);
    }
};


class Solution {
public:
    ll mod = 1e9 + 7;
    vector<pair<ll,int>>smal;
    ll ans = 0;
    SparseTable<ll> sp;
    vector<ll>prefS;

    void preprocess(vector<ll>& nums){
        for(int i = 0; i < nums.size(); ++ i){
            smal.push_back(make_pair(nums[i], i));
        }
        sort(smal.rbegin(), smal.rend());

    }

    void solve(int l, int r){
        if(l <= r and (not smal.empty())){
            ll rsum = sp.query(l, r); // to get min
            rsum *= (prefS[r] - (l == 0 ? 0 : prefS[l - 1]));

            cout << l << " " << r << " " << rsum <<endl;
            ans = max(ans, rsum);
            int nxt_smaller_idx = smal.back().second;
            smal.pop_back();
            if(not smal.empty() and smal.back().second > nxt_smaller_idx){
                solve(nxt_smaller_idx + 1, r);
                solve(l, nxt_smaller_idx - 1);
            }else{
                solve(l, nxt_smaller_idx - 1);
                solve(nxt_smaller_idx + 1, r);
            }
        }
        else{
            // assert(l > r);
            if(l <=r)
            cout <<"! " << l << " " << r <<endl;
        }
    }

    int maxSumMinProduct(vector<int>& arr) {
        vector<ll>nums((int)arr.size());
        for(int i = 0; i < arr.size(); ++ i){
            nums[i] = arr[i];
        }
        preprocess(nums);
        prefS = nums;
        for(int i = 1; i < nums.size(); ++ i) prefS[i] += prefS[i - 1];

        sp.init(nums);
        solve(0, (int)nums.size() - 1);

        return (int)(ans%mod);
    }
};

int main(){
    // vector<int> v { 2, 3, 3, 1, 2 };
    vector<int> v {1,1,3,2,2,2,1,5,1,5};
    // vector<int>{0,1,2,3,4,5,6,7,8,9}; 
    Solution obj;
    cout << obj.maxSumMinProduct(v) << endl;
    return 0;
}