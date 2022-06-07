// problem link: https://codeforces.com/problemset/problem/896/A
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
string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string fa = "What are you doing while sending \"";
string fb = "\"? Are you busy? Will you send \"";
string fc = "\"?";


char dfs(ll n, ll k, vector<ll> &dp){
    if(n == 0)  return f0[k];
    if(k < fa.length()) return fa[k];
    k -= fa.length();

    if(k < dp[n - 1]) return dfs(n - 1, k, dp);
    k -= dp[n - 1];

    if(k < fb.length()) return fb[k];
    k -= fb.length();

    if(k < dp[n - 1]) return dfs(n - 1, k , dp);
    k -= dp[n - 1];

    return fc[k];
}

void testcase(int test){ // testcasesid

    int q;
    vector<pair<ll,ll>>question;
    cin >> q;
    ll maxn = 0;
    while(q){
        -- q;
        ll n, k;
        cin >> n >> k;
        question.push_back({n,k});
        maxn = max(maxn, n);
    }

    vector<ll> dp(maxn + 1);
    dp[0] = f0.length();
    for(int i = 1; i <= maxn; ++ i){
        dp[i] = fa.length() + dp[i - 1] + fb.length() + dp[i - 1] + fc.length();
        dp[i] = min(dp[i], (ll)1e18+1);
    }

    for(auto nk: question){
        ll n = nk.first, k = nk.second;
        if(dp[n] < k) putchar('.');
        else{
            -- k;
            cout << dfs(n, k, dp);
        }
    }


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