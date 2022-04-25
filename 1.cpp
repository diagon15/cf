// problem link:
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// template <class T>
// using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;
#define fastio    ios_base::sync_with_stdio(false);
#define endl "\n";

void yes(){ cout<<"YES"<<"\n"; return ;}
void no(){ cout<<"NO"<<"\n"; return ;}
template<typename T> void pnl(T a){ cout<<a<<"\n"; return;}


void _print(int x) { cout<<x;}
void _print(long long x) { cout<<x;}
void _print(char x) { cout<<x;}
void _print(string x) { cout<<x;}
void _print(bool x) { cout<<x;}
void _print(size_t x) { cout<<x;}

void _print(pair<int,int> x) { _print("{"); _print(x.first); _print(","); _print(x.second); _print("}\n"); }
void _print(pair<long long,long long> x) { _print("{"); _print(x.first); _print(","); _print(x.second); _print("}\n"); }
void _print(pair<string,string> x) { _print("{"); _print(x.first); _print(","); _print(x.second); _print("}\n"); }

template<class T> void _print(vector<T> v){    cout<< "[";     for(T i: v) _print(i), _print(' ');      cout<<"]";      }
template<class T> void _print(set<T> v){    cout<< "[";     for(T i: v) _print(i), _print(' ');      cout<<"]";      }
template<class T> void _print(multiset<T> v){    cout<< "[";     for(T i: v) _print(i), _print(' ');      cout<<"]";      }


#define debug(x)    cout<<#x<<" "; (_print(x)); cout<<"\n";
// #define debug(x)


#define ll long long
/*
template <class T>
class Fenwick {
    private:
    int getNext(int x){
        return x + ((x) & (-x));
    }
    int getParent(int x){
        return x - (x & (-x));
    }
    public:
    vector<T> data;
    // Fenwick(int n){data = vector<int>(n + 1, 0); }
    Fenwick(){}
    void init(vector<T> &arr){
    // Fenwick(vector<T> &arr){
        // data.resize(arr.size(), 0);
        data = arr;
        for(int i = 1 ; i < arr.size(); ++ i){
            int j = getNext(i);
            if(j < data.size())
                data[j] += data[i];
        }
    }

    void update(int idx, T delta){
        while(idx < data.size()){
            data[idx] += delta;
            idx = getNext(idx);
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
*/


template <class T>
class SparseTable {
    vector<T> data;
    vector<vector<T>> spt;
    int LOG = 0;
    vector<int>log_val;

    public:
    SparseTable(vector<T> &arr){
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

void testcase(int test){ // testcasesid

    // Fenwick<int>F;
    vector<int>v({0,1,2,3,2});
    // F.init(v);
    // cout << F.rangeSum(1,4) <<endl;
    // cout << F.rangeSum(1,3) <<endl;

    SparseTable<int>sp(v);

    cout << sp.query(0, 4) <<endl;
    cout << sp.query(1, 4) <<endl;
    cout << sp.query(4, 4) <<endl;
    cout << sp.query(3, 3) <<endl;
    cout << sp.query(2, 3) <<endl;


    return;
}


int32_t main(){
    fastio;
    int test=1,z=1;
    // cin>>test;
    while(z<=test){
        testcase(z); z++;
    }
    return 0;
}
/*
for std::lcm use -std=c++17 to compile locally

g++ *.cpp > log.txt 2>&1

topics:
*/