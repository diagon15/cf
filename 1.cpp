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


void testcase(int test) { // testcasesid

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>>g(n, vector<pair<int, int>>());
    map<pair<int, int>, int>getid;
    for(int i = 0; i < m; ++ i){
        int u, v, w;
        cin >> u >> v >> w;
        -- u, -- v;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
        getid[{u, v}] = i + 1;
        getid[{v, u}] = i + 1;
    }

    int dist[n];
    fill(dist, dist + n, n + 1);
    dist[0] = 0;
    priority_queue<array<int, 3>>pq;
    pq.push({0, 0, 0});
    // <-weight, -edges_encountered, node>

    vector<pair<int, int>>par(n);

    while(not pq.empty()){
        auto arr = pq.top();
        pq.pop();
        int edges_enc = arr[1];
        int node = arr[2];

        for(auto nxt: g[node]){
            int dis = dist[node] + nxt.second;
            if(dist[nxt.first] > dis){
                dist[nxt.first] = dis;
                pq.push({- dis, edges_enc - 1, nxt.first});
                par[nxt.first] = make_pair(1-edges_enc, node);
            }
        }
    }

    vector<array<int, 3>>shortlisted;
    for(int i = 1; i < n; ++ i){
        shortlisted.push_back({par[i].first, i, par[i].second});
    }

    sort(shortlisted.begin(), shortlisted.end());

    while(shortlisted.size() > k) shortlisted.pop_back();

    cout << shortlisted.size() << endl;

    for(int i = 0; i < shortlisted.size(); ++ i)
    {
        int u = shortlisted[i][1];
        int v = shortlisted[i][2];
        cout << getid[{u, v}] << " ";
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