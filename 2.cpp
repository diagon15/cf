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

void yes() { cout << "YES" << "\n"; return; }
void no() { cout << "NO" << "\n"; return; }
template<typename T> void pnl(T a) { cout << a << "\n"; return; }
// std::apply([](auto&&... args) {((cout << args <<" "), ...); }, tp); // tuple print

void _print(int x) { cout << x; }
void _print(long long x) { cout << x; }
void _print(char x) { cout << x; }
void _print(string x) { cout << x; }
void _print(bool x) { cout << x; }
void _print(size_t x) { cout << x; }

void _print(pair<int, int> x) { cout << x.first << "," << x.second; }
// void _print(pair<int,int> x) { _print("{"); _print(x.first); _print(","); _print(x.second); _print("}\n"); }
void _print(pair<long long, long long> x) { _print("{"); _print(x.first); _print(","); _print(x.second); _print("}\n"); }
void _print(pair<string, string> x) { _print("{"); _print(x.first); _print(","); _print(x.second); _print("}\n"); }

template<class T> void _print(vector<T> v) { cout << "[";     for (T i : v) _print(i), _print(' ');      cout << "]"; }
template<class T> void _print(set<T> v) { cout << "[";     for (T i : v) _print(i), _print(' ');      cout << "]"; }
template<class T> void _print(multiset<T> v) { cout << "[";     for (T i : v) _print(i), _print(' ');      cout << "]"; }


#define debug(x)    cout<<#x<<" "; (_print(x)); cout<<"\n";
// #define debug(x)

template<typename T>
void p2darr(T* arr, int n, int m) { for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) cout << arr[i][j] << " "; cout << "\n"; } }
template<typename T>
void pvpair(T& vp) { for (int i = 0; i < vp.size(); ++i) cout << '{' << vp[i].first << ", " << vp[i].second << '}' << endl; }

vector<int>pm, pM;
vector<int>sm, sM;

int N;
struct seg {
    vector<int>a, b;

    void build(vector<int>& arr, int v, int l, int r) {
        if (l == r) a[v] = arr[l], b[v] = arr[l];
        else {
            int mid = l + (r - l) / 2;
            build(arr, 2 * v, l, mid);
            build(arr, 2 * v + 1, mid + 1, r);
            a[v] = min(a[2 * v], a[2 * v + 1]);
            b[v] = max(b[2 * v], b[2 * v + 1]);
        }
    }

    int getmin(int l, int r, int id = 1, int al = 0, int ar = N - 1) {
        if (r < al or ar < l) return INT_MAX;
        if (l <= al and ar <= r) return a[id];
        int mid = al + (ar - al) / 2;
        return min(getmin(l, r, id * 2, al, mid), getmin(l, r, id * 2 + 1, mid + 1, ar));
    }

    int getmax(int l, int r, int id = 1, int al = 0, int ar = N - 1) {
        if (r < al or ar < l) return INT_MIN;
        if (l <= al and ar <= r) return b[id];
        int mid = al + (ar - al) / 2;
        return max(getmax(l, r, id * 2, al, mid), getmax(l, r, id * 2 + 1, mid + 1, ar));
    }

    seg(vector<int>& arr) {
        a = vector<int>(4 * N);
        b = vector<int>(4 * N);
        build(arr, 1, 0, (int)arr.size() - 1);
    }
};


void testcase(int test) { // testcasesid

    int n;
    cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    pm = vector<int>(n);
    pM = vector<int>(n);
    sm = vector<int>(n);
    sM = vector<int>(n);
    sm[n - 1] = n - 1;
    sM[n - 1] = n - 1;

    for (int i = 1; i < n; ++i) {
        if (arr[pm[i - 1]] > arr[i]) pm[i] = i;
        else pm[i] = pm[i - 1];
        int j = n - 1 - i;
        if (arr[sm[j + 1]] > arr[j]) sm[j] = j;
        else sm[j] = sm[j + 1];
    }

    for (int i = 1; i < n; ++i) {
        if (arr[pM[i - 1]] < arr[i]) pM[i] = i;
        else pM[i] = pM[i - 1];
        int j = n - 1 - i;
        if (arr[sM[j + 1]] < arr[j]) sM[j] = j;
        else sM[j] = sM[j + 1];
    }

    int cnt = 0, pos = 0;
    N = arr.size();
    seg sg(arr);
    // debug(sm);
    // debug(sM);

    while (pos < n - 1) {
        int lo = pos, hi = n - 1, mid, res, res2;
        // a[pos] is smallest (consider)

        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if(sg.getmin(pos, mid) == arr[pos] and sg.getmax(pos , mid) == arr[mid]){
                res = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }

        // a[pos] is largest (consider)
        lo = pos, hi = n - 1;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if(sg.getmax(pos, mid) == arr[pos] and sg.getmin(pos, mid) == arr[mid]){
                res2 = mid;
                lo = mid + 1;
            }
            else    hi = mid - 1;
        }

        ++cnt;

        // cout << res << " " << res2 <<endl;
        pos = max(res, res2);
    }

    cout << cnt << endl;
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