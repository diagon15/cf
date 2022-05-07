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


void testcase(int test){ // testcasesid

    int n;
    cin >> n;
    vector<int>arr(n), brr(n), crr(n);
    // int arr[n];
    // int brr[n];
    // int crr[n];
    map<int, int>mpa, mpb;
    for(int i = 0; i < n; ++ i) cin >> arr[i], mpa[arr[i]] = i;
    for(int i = 0; i < n; ++ i) cin >> brr[i], mpb[brr[i]] = i;
    for(int i = 0; i < n; ++ i) cin >> crr[i];

    // set<int>visited;
    vector<int>visited(n + 1, 0);
    int cnt = 0;
    for(int i = 0; i < n; ++ i){
        if(crr[i] and visited[i] == 0 and (arr[i]^brr[i])){
            if(brr[i] == crr[i]) swap(arr, brr), swap(mpa, mpb);
            int val = arr[i];
            int pos = i;
            while(visited[pos] == 0){
                // debug(arr[pos]);
                // debug(pos);
                visited[pos] = 1;
                pos = mpb[arr[pos]];

            }
            // ++ cnt;
        }
        if(crr[i])  visited[i] = 1;
    }

    for(int i= 0; i < n; ++ i){
        int pos = i;
        if(visited[pos] == 0 and (arr[i]^brr[i])){
            while(visited[pos] == 0){
                visited[pos] = 1;
                pos = mpa[brr[pos]];
                // swap(arr,brr);
            }
            // debug(i);
            ++ cnt;
        }
    }
    int ans = 1;
    // debug(cnt);
    const int mod = 1e9 + 7;
    while(cnt > 0){
        ans *= 2;
        ans %= mod;
        -- cnt;
    }
    cout << ans << endl;
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

1
6
1 5 2 4 6 3
6 5 3 1 4 2
6 0 0 0 0 0
0 1 2 3 4 5

1
10
1 8 6 2 4 7 9 3 10 5
1 9 2 3 4 10 8 6 7 5
1 9 2 3 4 10 8 6 7 5


*/