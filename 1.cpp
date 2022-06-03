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
// std::apply([](auto&&... args) {((cout << args <<" "), ...); }, tp); // tuple print

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
// https://codeforces.com/problemset/problem/895/B

void testcase(int test){ // testcasesid

    int n, x,k;
    cin >> n >> x >> k;
    int arr[n];
    for(int i = 0; i < n; ++ i) cin >> arr[i];

    sort(arr, arr + n);

    vector<int>v;
    for(int i = 0; i < n - 1; ++ i){
        int val1 = ((arr[i] + x-1)/x);
        if(val1*x <= arr[i + 1]){
            int val2 = (arr[i + 1]/x);
            // cout << val1<< " " << val2 << endl;
            int freq = 1 + val2 - val1;
            v.push_back(freq);
        }
    }

    int p = 1, q = 1;
    for(int i = 1; i < v.size(); ++ i){
        v[i] += v[i - 1];
    }
    reverse(v.begin(), v.end());
    v.push_back(0);
    reverse(v.begin(), v.end());
    int ans = 0;
    // debug(v);
    while(p < v.size() and q < v.size()){
        if(v[q] - v[p - 1] == k) mp[p]++; //ans += (p == q? 1 : 2);
        if(v[q] - v[p - 1] > k) ++ p;
        else ++ q;
        q = max(p, q);
    }



    cout << ans << endl;


    return;
}


int32_t main(){
    fastio;
    int test=1,z=1;
    // cin>>test;
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