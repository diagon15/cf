// problem link:https://codeforces.com/problemset/problem/917/B?csrf_token=47ad6ba10e886a16b4fed64d823e7458&f0a28=1
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
// std::apply([](auto&&... args) {((cout << args <<" "), ...); }, tp); // tuple print

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

const int N = 101;
int dp[N][N][28][2];
vector<vector<pair<int,int>>>adj;

int dfs(int u, int v, int k, int op){
    if(dp[u][v][k][op] != -1) return dp[u][v][k][op];

    if(not op){
        int win = 0;
        for(auto &x: adj[u]){
            if(x.second >= k){
                win |= dfs(x.first, v, x.second , op^1);
                if(win == 1) break;
            }
        }
        return dp[u][v][k][op] = win;
    }
    else{
        int win = 1;
        for(auto &x: adj[v]){
            if(x.second >= k){
                win &= dfs(u, x.first, x.second , op^1);
                if(win == 0) break;
            }
        }
        return dp[u][v][k][op] = win;
    }
}



void testcase(int test){ // testcasesid

    int n, m;
    cin >> n >> m;
    adj = vector<vector<pair<int,int>>>(n);
    fill_n(&dp[0][0][0][0], N*N*28*2, -1);
    for(int i = 0; i < m; ++ i){
        int t1, t2;
        char ch;
        cin >> t1 >> t2 >> ch;
        -- t1, -- t2;
        int chint = ch - 'a';
        adj[t1].push_back({t2,chint});
    }

    for(int max = 0; max < n; ++ max){
        for(int alice = 0; alice < n; ++ alice){
            char res = (dfs(max, alice, 0, 0) ? 'A' : 'B');
            putchar(res);
        }
        puts("");
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