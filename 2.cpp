// problem link: https://codeforces.com/contest/1594/problem/D
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

int c[2];
bool ok;
int n , m;

void dfs(int idx, vector<int>&color, vector<vector<pair<int,int>>>&adj){
    c[color[idx]] += (idx <= n);

    for(auto x: adj[idx]){
        if(color[x.first] == -1){
            color[x.first] = color[idx] ^ x.second;
            dfs(x.first, color, adj);
        }
        else if(color[x.first] != color[idx]^x.second){
            ok = false;
            return;
        }
    }

}

void testcase(int test){ // testcasesid

    cin >> n >> m;

    vector<int>color(n + m + 1, -1);
    vector<vector<pair<int,int>>>adj(n + m + 1);
    int fake = n + 1;
    for(int i = 0; i < m; ++ i){
        int a,  b;
        string c;
        cin >> a >> b >> c;

        if(c == "crewmate"){
            adj[a].push_back({fake, 1});
            adj[fake].push_back({a, 1});
            adj[fake].push_back({b, 1});
            adj[b].push_back({fake, 1});
            ++ fake;
        }
        else{
            adj[a].push_back({b, 1});
            adj[b].push_back({a, 1});
        }
    }

    int ans = 0;
    ok = true;

    for(int i = 1; i <= n; ++ i){
        if(color[i] == -1){
            color[i] = 0;
            c[0] = 0, c[1] = 0;
            dfs(i, color, adj);
            ans += max(c[0], c[1]);
        }
    }

    if(not ok )ans = -1;
    cout << ans<<endl;


    return;
}


int32_t main(){
    fastio;
    int test=1,z=1;
    cin>>test;
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