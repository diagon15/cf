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
    vector<int>arr(n);
    for(int i = 0; i < n; ++ i){
        cin >> arr[i];
    }

    arr.push_back(0);
    vector<ll>suf(n + 1);
    suf[n] = 0;
    for(int i = n - 1; i >= 0; -- i){
        suf[i] = suf[i + 1] + arr[i];
    }

    log(suf);
    // return ;
    vector<pair<ll, ll>>stk;
    stk.push_back({suf[0], 0});
    for(int i = 1; i < n; ++ i){
        if(stk.back().first < suf[i]){
            stk.push_back({suf[i] , i});
        }
    }
    log(stk);
    for(int i =0;i  < stk.size(); ++ i){
        // cerr << stk[i].first <<" " << stk[i].second << endl;
    }
    // return;

    int pos = n;
    int ans = 0;
    while(stk.size()){
        int idx = upper_bound(stk.begin(), stk.end(), pair<ll,ll>{suf[pos], pos}) - stk.begin();
        // cerr <<"idx1: " << idx <<endl;

        if(idx == stk.size()){

            idx = lower_bound(stk.begin(), stk.end(), pair<ll,ll>{suf[pos], pos -1}) - stk.begin();
            // cerr <<"idx2: " << idx <<endl;

            if(idx == stk.size()){
                -- pos;
                ans += -1;
            }
            else pos = stk[idx].second;
        }
        else{
            ans += pos - stk[idx].second;
            pos = stk[idx].second;
        }

        while(stk.size() and stk.back().second >= pos) stk.pop_back();
    }

    cout << ans << endl;


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