// problem link:
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
    set<pair<int, int>>st;
    oset<int>osti;
    multiset<int>mst;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        st.insert({ val, i + 1 });
        mst.insert(val);
        osti.insert(i + 1);
    }
    int prv_idx = -1;
    prv_idx = (*st.begin()).second;
    osti.erase(prv_idx);
    mst.erase(mst.begin());
    st.erase(st.begin());

    ll cost = prv_idx;
    while (mst.size()) {
        int val = *mst.begin();
        auto it = st.lower_bound({ val, prv_idx });
        if (it != st.end() and it->first == val) {
            int pref_ids = osti.order_of_key(it->second + 1);
            int rem_ids = osti.order_of_key(prv_idx);
            cost += pref_ids - rem_ids;
        }
        else {
            it = st.begin();
            int lesseq_ids = osti.order_of_key(it->second + 1);
            int further_ids = osti.size() - osti.order_of_key(prv_idx + 1);
            cost += lesseq_ids + further_ids;
        }

        prv_idx = it->second;
        mst.erase(mst.begin());
        osti.erase(prv_idx);
        st.erase(it);
        // cout << cost << endl;
    }

    cout << cost << endl;


    // cout << "Case #" << test << ": " << ans << endl;
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