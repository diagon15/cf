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
template<class T> void _print(map<T, T> v) { dbg << "[";     for (pair<T, T> i : v) _print(i), _print(' ');      dbg << "]"; }


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

    int n;
    cin >> n;


    vector<vector<pair<int ,int>>>dp(n, vector<pair<int, int>>(10, {-1, -1}));
    vector<vector<int>>parent(n, vector<int>(10, -1));
    for(int i = 1; i < 10; ++ i){
        dp[0][i] = {i, i};
    }
    // dp[0][0] = {-1, -1};

    for(int i = 0; i < n - 1; ++ i){
        for(int curr = 9; curr > 0; -- curr){
            for(int nxt = curr; nxt > 0 ; -- nxt){
                if(dp[i][curr].first == -1) continue;

                ll product = dp[i][curr].first * nxt;
                ll sum = dp[i][curr].second + nxt;
                if(product >= sum){
                    if(dp[i + 1][nxt].first == -1 or (dp[i + 1][nxt].first != -1 and product < dp[i + 1][nxt].first)){
                        dp[i + 1][nxt] = {product, sum};
                        parent[i + 1][nxt] = curr;
                    }
                }
            }
        }
    }

    int last = -1;
    ll product = 1e18;
    for(int i = 0; i < 10; ++ i){
        if(dp[n - 1][i].first != -1 and dp[n - 1][i].first < product){
            product = dp[n - 1][i].first;
            last = i;
        }
    }
    assert(last != -1);

    string ans = "";
    for(int i = n - 1; i >= 0; -- i){
        ans += to_string(last);
        last = parent[i][last];
    }
    reverse(ans.begin(), ans.end());
    cout <<  ans << endl;


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

// above solution is incomplete

Determine a valid integer having K digits such that the product of digits
of the integer is greater than or equal to the sum of digits of the integer
 and the product of the digits is minimized. If more than 1 such integer exists,
determine the smallest possible integer.
topics:
1 - 1
2 - 22
3 - 123
4 - 1124
5 - 11222
6 - 111126
7 - 1111134
8 - 11111223
9 - 111111135
10 -1111111144
------------ TEEEPS --------------------
If you have an observation, complement of that observation can be a better observation for code!!

in dp, try to recognise the number of DIFFERENT states first. else your going wrong way!

*/