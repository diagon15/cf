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

void dfs(int r, int c, vector<string>& v, vector<vector<bool>> &vis){
    int n  = v.size();
    int m = v[0].size();
    vis[r][c] = true;
    v[r][c] = 'X';

    if(r + 1 < n and v[r + 1][c] == '.'){
        dfs(r + 1, c, v, vis);
    }
    if(c + 1 < m and v[r][c + 1] == '.'){
        dfs(r, c + 1, v, vis);
    }

}


void testcase(int test){ // testcasesid

    int n,m;
    cin >> n >> m;
    vector<string>v(n);
    for(int i = 0; i < n; ++ i){
        cin >> v[i];
    }

    vector<vector<bool>>vis(n, vector<bool>(m, false));
    dfs(0, 0, v, vis);

    int arr[m + 1];

    for(int j = 0; j < m; ++ j){
        int sum  = 0;
        for(int i = 0; i < n; ++ i){
            if(v[i][j] == '.') ++ sum;
        }
        arr[j + 1] = sum;
    }
    for(int i = 1 ; i <= m; ++ i) arr[i] += arr[i - 1];

    for(int i = 0; i < n; ++ i){
        for(int j = 0 ; j < m; ++ j){
            cout << v[i][j];
        }
        cout <<endl;
    }
    int q;
    cin >> q;
    while(q){
        int l, r;
        cin >> l >> r;
        // cout << arr[r] - arr[l - 1];
        if(arr[r] - arr[l - 1] > 0) no();
        else yes();
        -- q;
    }


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