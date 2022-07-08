// problem link: https://cses.fi/problemset/task/1136/
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

vector<vector<int>>tree;

void testcase(int test) { // testcasesid

    int n, m;
    cin >> n >> m;
    tree = vector<vector<int>>(n, vector<int>());
    for(int i = 0; i < n - 1; ++ i){
        int u, v;
        cin >> u >> v;
        -- u, -- v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    unordered_map<int, int> keys;

    for(int i = 0; i < m; ++ i){
        int a, b;
        cin >> a >> b;
        -- a, -- b;
        keys[a].insert(i);
        keys[b].insert(i);
        ++ indeg[a];
        ++ indeg[b];
    }

    queue<int>leaves;

    for(int i = 0; i < n; ++ i){
        if(tree[i].size() == 1) leaves.push(i);
    }
    vector<int>freq(n, 0);
    for(int i = 0; i < n; ++ i) freq[i] = keys[i].size();


    int ans[n];

    while(not leaves.empty()){
        int sz = leaves.size();
        while(sz){
            -- sz;
            int leaf = leaves.front();
            ans[leaf] = freq[leaf];
            for(auto &nxt: tree[leaf]){
                // if(vis[nxt]) continue;

            }
        }
    }


    return;
}



int32_t main() {
    fastio;
    int test = 1, z = 1;
    // cin >> test;
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