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
#define endl "\n"
#define dbg cerr

void yes() { cout << "YES" << "\n"; return; }
void no() { cout << "NO" << "\n"; return; }
template<typename T> void pnl(T a) { cout << a << "\n"; return; }
// std::apply([](auto&&... args) {((cout << args <<" "), ...); }, tp); // tuple print

void _print(int x) { dbg << x; }
void _print(long long x) { dbg << x; }
void _print(char x) { dbg << x; }
void _print(string x) { dbg << x; }
void _print(bool x) { dbg << x; }
void _print(size_t x) { dbg << x; }

void _print(pair<int, int> x) { dbg << x.first << "," << x.second; }
// void _print(pair<int,int> x) { _print("{"); _print(x.first); _print(","); _print(x.second); _print("}\n"); }
void _print(pair<long long, long long> x) { _print("{"); _print(x.first); _print(","); _print(x.second); _print("}\n"); }
void _print(pair<string, string> x) { _print("{"); _print(x.first); _print(","); _print(x.second); _print("}\n"); }

template<class T> void _print(vector<T> v) { dbg << "[";     for (T i : v) _print(i), _print(' ');      dbg << "]"; }
template<class T> void _print(set<T> v) { dbg << "[";     for (T i : v) _print(i), _print(' ');      dbg << "]"; }
template<class T> void _print(multiset<T> v) { dbg << "[";     for (T i : v) _print(i), _print(' ');      dbg << "]"; }


#ifndef ONLINE_JUDGE
#define log(x)    dbg<<#x<<" = "; (_print(x)); dbg<<"\n";
#else
#  define log(x) 0
#endif


template<typename T>
void p2darr(T* arr, int n, int m) { for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) cout << arr[i][j] << " "; cout << "\n"; } }
template<typename T>
void pvpair(T& vp) { for (int i = 0; i < vp.size(); ++i) cout << '{' << vp[i].first << ", " << vp[i].second << '}' << endl; }

vector<vector<int>>g;
vector<int>vis;

bool dfs(int node, int cnt, int par){
    if(vis[node] != -1){
        return (cnt&1) == (vis[node]&1);
    }
    vis[node] = cnt;

    bool res = true;
    for(auto child: g[node]){
        if(child == par) continue;
        res = res and  dfs(child, cnt + 1, node);
        if(res == false) break;
    }

    return res;
}

void testcase(int test) { // testcasesid


    int n;
    cin >> n;
    bool ok = true;
    g = vector<vector<int>>(n);
    vis = vector<int>(n, -1);
    for(int i = 0; i < n; ++ i){
        int a, b;
        cin >> a >> b;
        --a,--b;
        if(a == b) ok = false;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    if(not ok) return no();
    for(int i = 0;  i < n; ++ i){
        if(g[i].size() > 2) return no();
    }

    int res = 1;
    for(int i = 0; i < n; ++ i){
        if(vis[i] == -1)
        res &= dfs(i, 0, -1);
    }

    res ? yes() : no();
    // cout << "Case #" << test << ": " << ans << endl;
    return;
}



int32_t main() {
    fastio;
    int test = 1, z = 1;
    cin >> test;
    while (z <= test) {
        testcase(z); z++;
    }
    return 0;
}
/*
for std::lcm use -std=c++17 to compile locally

g++ *.cpp > log.txt 2>&1

topics:

------------ TEEEPS --------------------
If you have an observation, complement of that observation can be a better observation for code!!

in dp, try to recognise the number of DIFFERENT states first. else your going wrong way!

*/