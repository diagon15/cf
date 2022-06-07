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
template<class T> void _print(deque<T> v){    cout<< "[";     for(T i: v) _print(i), _print(' ');      cout<<"]";      }
template<class T> void _print(set<T> v){    cout<< "[";     for(T i: v) _print(i), _print(' ');      cout<<"]";      }
template<class T> void _print(multiset<T> v){    cout<< "[";     for(T i: v) _print(i), _print(' ');      cout<<"]";      }


#define debug(x)    cout<<#x<<" "; (_print(x)); cout<<"\n";
// #define debug(x)


void testcase(int test){ // testcasesid
/*
    vector<vector<int>>v{{1,2,3}, {4,8,332,5},{4,5},{1,2,3},{4,8,332,5}};
    v.erase(unique(v.begin(), v.end()), v.end());
    debug(v);
    // for(int i = 0; i < v.size(); ++ i){
    //     debug(v[i]);
    // }cout << "\n";

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    debug(v);
    // for(int i = 0; i < v.size(); ++ i){
    //     debug(v[i]);
    // }cout << "\n";
*/

    vector<deque<int>> vdq{{1, 2, 1}, {1, 1, 2}, {1, 2, 1}};
    sort(vdq.begin(), vdq.end());
    vdq.erase(unique(vdq.begin(), vdq.end()), vdq.end());
    // debug(vdq);
    for(int i = 0; i < vdq.size(); ++ i){
        for(auto &e: vdq[i]) cout << e << " ";
        cout << endl;
    }
    cout << endl;

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