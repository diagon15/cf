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


struct segTree {
    static constexpr ll unit = -1e17;

    vector<ll>t;
    ll n;

    segTree(ll n = 0, ll def = unit): t(2*n, def), n(n) {}

    // any associative function
    ll merge(ll a, ll b){
        return max(a, b);
    }

    void update(ll pos, ll val){
        for(t[pos += n] = val; pos/=2; ){
            t[pos] = merge(t[pos * 2], t[pos * 2 + 1]);
        }
    }
    // query [b, e)
    ll query(ll b, ll e){
        ll ra = unit, rb = unit;
        for(b +=n, e += n; b < e;  b/= 2, e/= 2){
            if(b%2) ra = merge(ra, t[b++]);
            if(e%2) rb = merge(rb, t[-- e]);
        }
        return merge(ra, rb);
    }
};

void testcase(int test) { // testcasesid


    ll n;
    cin >> n;

    segTree sg(n + 5);
    vector<ll>dp(n + 1, (ll)-1e18);

    vector<ll>arr(n);
    for(int i = 0; i < n; ++ i) cin >> arr[i];


    set<ll>st;
    st.insert(0);
    ll sum = 0;
    for(int i = 0; i < n; ++ i) st.insert(sum +=arr[i]);
    // log(st);
    map<ll,ll>compress;
    ll id = 0;
    for(auto &val: st) compress[val] = id ++ ;

    // solving
    dp[0] = 0;
    sum = 0;
    sg.update(compress[0], 0);
    for(ll i = 0; i < n; ++ i){
        dp[i + 1] = dp[i];
        if(arr[i] < 0)
            -- dp[i + 1];
        else if(arr[i] > 0)
            ++ dp[i + 1];

        sum += arr[i];
        ll seg_idx = compress[sum];
        ll part1 = sg.query(0, seg_idx);
        dp[i + 1] = max(dp[i + 1], part1 + i + 1);

        ll curr = sg.query(seg_idx, seg_idx + 1);
        if(curr < dp[i + 1] - i - 1) sg.update(seg_idx, dp[i + 1] - i - 1);

    }


    cout << dp[n] << endl;


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