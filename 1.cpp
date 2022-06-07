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
string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string str1 = "What are you doing while sending ";
string str2 = "? Are you busy? Will you send ";
string str3 = "?";


void testcase(int test){ // testcasesid
    cout << (str1 + str2 + str3).length() + 4 << endl;
    pnl(str1.length());
    pnl(str2.length());
    pnl(f0.length());
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
    string F[maxn + 1];
    fill_n(&F[0], maxn + 1, "-");
    F[0] = f0;
    for(int i = 1; i <= maxn; ++ i){
        F[i] = str1 + "\"" + F[i - 1] + "\"" + str2 + "\"" + F[i - 1] + "\"" + str3;
    }
    // debug(f0.length());
    debug(F[1].length());
    debug(F[2].length());
    // cout << F[1].substr(193) << endl;
    // debug(F[2]);
    // cout << F[1] << endl;

    for(auto &nk: question){
        ll n = nk.first, k = nk.second;
        if(F[n].size() < k) putchar('.');
        else putchar(F[n][k-1]);
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