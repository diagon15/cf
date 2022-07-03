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

template<typename T>
void p2darr(T* arr, int n, int m) { for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) cout << arr[i][j] << " "; cout << "\n"; } }
template<typename T>
void pvpair(T& vp) { for (int i = 0; i < vp.size(); ++i) cout << '{' << vp[i].first << ", " << vp[i].second << '}' << endl; }


void testcase(int test){ // testcasesid

    int n;
    cin >> n;
    vector<string>s(2);
    cin >> s[0] >> s[1];
    while(s[0].back() == '.' and s[1].back() == '.'){
        s[0].pop_back();
        s[1].pop_back();
    }

    reverse(s[0].begin(), s[0].end());
    reverse(s[1].begin(), s[1].end());

    while(s[0].back() == '.' and s[1].back() == '.'){
        s[0].pop_back();
        s[1].pop_back();
    }
    reverse(s[0].begin(), s[0].end());
    reverse(s[1].begin(), s[1].end());
    // s[0] += ".";
    // s[1] += ".";

    n = s[0].size();
    // int dp[2][n];
    vector<vector<int>>dp(2, vector<int>(n));
    const int MAX = 1e8;
    // fill_n(&dp[0][0],2*n, MAX);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j)     dp[i][j] = 1e8;
    }
    // if(s[0][0] == '*') dp[0][0] = 0;
    // else if(s[1][0] == '*') dp[1][0] = 0;
    dp[0][0] = 0;
    dp[1][0] = 0;

    for(int i = 0; i + 1 < n; ++ i){
        dp[0][i + 1] = min({dp[0][i + 1], dp[0][i] + 1 + (s[1][i] == '*' ? 1 : 0), dp[1][i] + 2});
        dp[1][i + 1] = min({dp[1][i + 1], dp[1][i] + 1 + (s[0][i] == '*' ? 1 : 0), dp[0][i] + 2});
    }

    int ans;cp t
    if(s[0][n - 1] == '*' and s[1][n - 1] == '*') ans = min(dp[0][n - 1], dp[1][n - 1]) + 1;
    else if(s[0][n - 1] == '*') ans = dp[0][n - 1];
    else ans = dp[1][n - 1];


    auto pit = [&](){
        for(int i = 0; i < 2; ++ i){
            for(int j = 0; j < n; ++ j){
                cout << dp[i][j] ;
            }
            cout << endl;
        }
    };

    // pit();
    cout << ans << endl;
    // cout << min(dp[0][n - 1] - 1 , dp[1][n -1] - 1) << endl;



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

------------ TEEEPS --------------------
If you have an observation, complement of that observation can be a better observation for code!!

in dp, try to recognise the number of DIFFERENT states first. else your going wrong way!

*
.

.
*

*
*

.
.

dp[0][i + 1] = min(dp[0][i + 1], dp[0][i] + 1 + (dp[1][i] == '*' ? 1 : 0));
dp[1][i + 1] = min(dp[1][i + 1], dp[1][i] + 1 + (dp[0][i] == '*' ? 1 : 0));

3
*.*
.*.

0xx
0xx

01x
02x

013
022

*/