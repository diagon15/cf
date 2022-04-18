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


void func(const int a){
    pnl(a);
}

void testcase(int test){ // testcasesid

    int n, r, b;

    cin >> n >> r >> b;

    // int t1 = r / b;
    // cout <<  << endl;
    // int freq = (r) / (b + 1);
    // freq = (freq - ((b+1)* freq - r)) / b;
    // while(r > 0 or b > 0){
    //     for(int i = 0; i < min(freq, r); ++ i) cout << "R";
    //     r -= freq;
    //     if(b > 0)
    //     cout << "B";
    //     -- b;
    // }


    int num_grps = b + 1;
    int max_freq_in_each_grp = (r + b) / (b + 1);
    int empty_last = max_freq_in_each_grp*(b + 1) - r;
    int last_grp = max_freq_in_each_grp - empty_last;
    if(empty_last >= b){
        max_freq_in_each_grp--;
        last_grp += b;
        empty_last -= b;
    }
    // debug(max_freq_in_each_grp);
    // debug(last_grp);
    string s ="";
    for(int i = 0; i < b; ++ i){
        for(int j = 0; j < max_freq_in_each_grp; ++ j) s +="R";
        s += "B";
    }
    for(int i = 0; i < last_grp; ++ i) s += "R";

    cout << s <<endl;



    return;
}
/*

RRBRRBRRBRRBRRBRRBR

RRBRRBRRBRRR

*/

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