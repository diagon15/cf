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


void proc(vector<int>&pr, int &ans){
    if(pr.size() == 0) return;
    int last = 0;
    for(int i = 0; i < pr.size(); ++ i){
        if(pr[i]== pr[0]) last = i;
        else break;
    }

    -- pr[last];

    for(int i = 0; i < pr.size(); ++ i) -- pr[i];

    ++ ans;
    while(not pr.empty() and pr.back() <= 0) pr.pop_back();

    proc(pr, ans);
}

void testcase(int test){ // testcasesid

    int n;
    cin >> n;
    int par[n + 1];

    map<int,int>mp;
    for(int i = 2; i <= n; ++ i){
        cin >> par[i];
        ++ mp[par[i]];
    }
    vector<int>v;

    for(auto &u:mp){
        v.push_back(u.second);
    }

    v.push_back(1);
    sort(v.rbegin(), v.rend());

    int time = v.size();
    int ans = time, buff = 0;
    vector<int>pr;

    for(int i = 0 ; i < v.size(); ++ i){
        int calc = v[i]  - (time - (i));
        if(calc > 0){
            pr.push_back(calc);
        }
    }

    sort(pr.rbegin(), pr.rend());

    proc(pr,ans);

    // cout << preans << endl;

    // ans += preans;
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