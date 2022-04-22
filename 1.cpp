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


void testcase(int test){ // testcasesid

    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for(int i = 0; i < n; ++ i)
        cin >> v[i];

    int arr[n][m];
    // fill_n(arr, sizeof arr, 0);
    fill(&arr[0][0], &arr[0][0] + sizeof(arr), 0);


    for(int i = 0;  i < n; ++ i){
        for(int j = 0; j < m; ++ j){
            if(i > 0 and j > 0 and v[i][j] == '.' and v[i - 1][j] == 'X' and v[i][j - 1] == 'X'){
                arr[i][j] = 1;
            }
            if(i > 0) arr[i][j] += arr[i - 1][j];
        }
    }
    debug("fs");
    // for(int j = 0; j < m; ++ j){
    //     for(int i = 1; i < n; ++ i){
    //         arr[i][j] += arr[i - 1][j];
    //     }
    // }
    for(int i = 1; i < m; ++ i) arr[n - 1][i] += arr[n - 1][i - 1];

    int q;
    cin >> q;
    while(q>0){

        int l, r;
        cin >> l >> r;
        -- l, -- r;
        int res = arr[n - 1][r] - arr[n - 1][l];
        if(res > 0) no();
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