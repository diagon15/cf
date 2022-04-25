
#define ll long long
template <class T>
class Fenwick {
    private:
    int getNext(int x){
        return x + ((x) & (-x));
    }
    int getParent(int x){
        return x - ((x) & (-x));
    }
    public:
    vector<T> data;
    // Fenwick(int n){data = vector<int>(n + 1, 0); }
    Fenwick(){}
    void init(vector<T> &arr){
    // Fenwick(vector<T> &arr){
        // data.resize(arr.size(), 0);
        data = arr;
        // for(int i = 0; i < data.size(); ++ i) data[i] =
        for(int i = 1 ; i < arr.size(); ++ i){
            int j = getNext(i);
            if(j < data.size())
                data[j] += data[i];
        }
    }

    void update(int idx, T delta){
        while(idx < data.size()){
            data[idx] += delta;
            idx = getParent(idx);
        }
    }

    T getPrefixSum(int idx){
        T sum = data[0];
        while(idx > 0){
            sum += data[idx];
            idx = getParent(idx);
        }
        return sum;
    }

    T rangeSum(int l, int r){
        return getPrefixSum(r) - getPrefixSum(l - 1);
    }
};


class Solution {
public:
    ll mod = 1e9 + 7;
    vector<pair<ll,int>>smal;
    ll ans = LONG_LONG_MAX;
    Fenwick<ll> F;

    void preprocess(vector<ll>& nums){
        for(int i = 1; i < nums.size(); ++ i){
            smal.push_back(make_pair(nums[i], i));
        }
        sort(smal.rbegin(), smal.rend());

    }

    void solve(int l, int r){
        if(l <= r){
            ll rsum = F.rangeSum(l, r);
            rsum *=
            cout << l << " " << r << " " << rsum <<endl;
            ans = min(ans, rsum);
            int nxt_smaller_idx = smal.back().second;
            smal.pop_back();
            solve(l, nxt_smaller_idx - 1);
            solve(nxt_smaller_idx + 1, r);
        }
    }

    int maxSumMinProduct(vector<int>& arr) {
        vector<ll>nums(1 + (int)arr.size());
        for(int i = 1; i < arr.size(); ++ i){
            nums[i] = arr[i - 1];
        }
        // vector<ll>nums = arr;
        // reverse(nums.begin(),nums.end());
        // nums.push_back(0);
        // reverse(nums.begin(),nums.end());
        preprocess(nums);

        F.init(nums);
        solve(1, (int)nums.size() - 1);

        return (int)(ans%mod);
    }
};