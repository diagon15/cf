// problem link:
#include <bits/stdc++.h>
using namespace std;
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

    string s;
    cin >> s;


    ll num = 0;
    ll ans = 0;

    ll dp[2][3];
    memset(dp, 0, sizeof dp);
    dp[1][0] = 1;
    for(int i = 0; i < n; ++ i){
        if(s[i] == '+') -- num;
        else ++ num;

        ans += dp[num >= 0][abs(num)%3];

        ++ dp[num >= 0][abs(num) % 3];
        for(int i = 0;i < 2; ++ i){
            for(int j = 0; j < 3; ++ j) cout << dp[i][j]<< " " ;    cout << endl;
        }
        // debug(ans);
        cout << ans << endl;
    }

    for(int i = 0;i < 2; ++ i){
        for(int j = 0; j < 3; ++ j) cout << dp[i][j]<< " " ;    cout << endl;
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
*/