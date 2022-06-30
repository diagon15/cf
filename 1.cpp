// problem link:https://codeforces.com/problemset/problem/1045/I
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


// std::bitset
const int SZ = 26;
void testcase(int test){ // testcasesid

    int n;
    cin >> n;
    vector<string>v(n);
    for(int i = 0; i < n; ++ i) cin >> v[i];

    map<int,int>bs;


    for(auto &u: v){
        bitset<SZ>parity;
        for(auto &ch: u){
            parity.flip(ch-'a');
        }
        ++ bs[parity.to_ulong()];
    }

    ll ans  = 0;

    // for(auto &u: bs){
    //     ll a = u.second;
    //     ans += a*(a - 1) / 2;
    // }

    // for(int i = 0; i < SZ; ++ i){
    //     // ith place is odd
    //     for(int j = 0; j < (1<<SZ); ++ j){
    //         if((j>>i)&1){
    //             j += (1<<i);
    //             if(j  > (1<<SZ)) break;
    //         }

    //         ll op1 = bs[j];
    //         ll op2 = bs[(j|(1<<i))];
    //         ans += op1*op2;
    //     }
    // }


    for(auto &u: bs){
        // for(int i = 0; i < SZ; ++ i){
        //     if(u.first&(1<<i)){
        //         for(auto &v: bs){
        //             if(!(v.first&(1<<i)) and !((v.first|(1<<i))^u.first))
        //                 ans += u.second * v.second;
        //         }
        //     }
        // }

        // for(auto &v: bs){
        //     int a = u.first;
        //     int b = v.first;
        //     int cnt = bitset<26>(u.first^v.first).count();
        //     if(cnt == 0) ans += (u.second) * (u.second - 1) / 2;
        //     else if(cnt == 1 and u.first < v.first) ans += u.second * v.second;
        // }

        ans += u.second *1LL* (u.second - 1) / 2;
        for(int i = 0; i < SZ; ++ i){
            if(u.first&(1<<i)){
                ans += u.second *1LL* (bs[u.first - (1<<i)]);
            }
        }

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

------------ TEEEPS --------------------
If you have an observation, complement of that observation can be a better observation for code!!

in dp, try to recognise the number of DIFFERENT states first. else your going wrong way!

*/