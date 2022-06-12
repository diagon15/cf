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

void _print(pair<int, int> x) { cout << x.first << "," << x.second; }
// void _print(pair<int,int> x) { _print("{"); _print(x.first); _print(","); _print(x.second); _print("}\n"); }
void _print(pair<long long,long long> x) { _print("{"); _print(x.first); _print(","); _print(x.second); _print("}\n"); }
void _print(pair<string,string> x) { _print("{"); _print(x.first); _print(","); _print(x.second); _print("}\n"); }

template<class T> void _print(vector<T> v){    cout<< "[";     for(T i: v) _print(i), _print(' ');      cout<<"]";      }
template<class T> void _print(set<T> v){    cout<< "[";     for(T i: v) _print(i), _print(' ');      cout<<"]";      }
template<class T> void _print(multiset<T> v){    cout<< "[";     for(T i: v) _print(i), _print(' ');      cout<<"]";      }


#define debug(x)    cout<<#x<<" "; (_print(x)); cout<<"\n";
// #define debug(x)
int I(char ch){ return (int)(ch - 'a'); }

const ll mod = 1e9 + 7;

ll power(ll a, ll n){
    ll res = 1;
    while(n){
        if(n&1) res = (res * a) % mod;
        n /= 2;
        a = (a * a) % mod;
    }
    return res;
}

void testcase(int test){ // testcasesid
    // total substrings
    // longest substrings
    // minimum number of substrings

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int>limit(26), curr(26,0);
    for(int i = 0; i < 26; ++ i) cin >> limit[i];

    ll ans = 0;
    int ans2 = 0, ans3 = 0;
    int l = 0;
    for(int i = 0; i < n; ++ i){
        int idx = I(s[i]);
        curr[idx]++;

        while(curr[idx] > limit[idx]){
            -- curr[I(s[l])];
            ++ l;
        }

        ll len;
        len = i - l + 1;
        // debug(len);
        if(len == n) break;
        // len = min(len,(ll) n - 1);
        ans = (ans + len*(len + 1) / 2 + mod)%mod;

        len = i - 1 - l + 1;
        if(len){
            ans = ans + mod - len*(len + 1) / 2;
            ans %= mod;
        }
        ans2 = max((int)ans2, i - l + 1);
    }
    ans2 = min((int)ans2, n - 1);

    cout << ans << endl;
    cout << ans2 << endl;

    curr.clear();

    for(int i = 0; i < n; ++ i){
        int idx = I(s[i]);
        ++ curr[idx];

        if(curr[idx] > limit[idx]){
            ++ ans3;
            curr.clear();
            curr[idx] = 1;
        }
    }
    ++ ans3;
    if(ans3 == 1) ++ ans3;
    // if(ans3 == 0) ans3 = 2;

    cout << ans3 << endl;


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