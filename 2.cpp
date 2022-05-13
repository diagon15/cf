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



void testcase(int test){ // testcasesid

    string s;
    cin >> s;
    // s += "0";

    int n = s.length();
    // int psum[n + 1];
    vector<int>psum(n  + 1);
    psum[0] = 0;
    for(int i = 0; i < n; ++ i){
        psum[i + 1] = psum[i] + (s[i] == '1' ? 1 : 0);
    }
    vector<int>zeros;
    zeros.push_back(-1);
    for(int i = 0; i < n; ++ i) if(s[i] == '0') zeros.push_back(i);
    zeros.push_back(n);

    // debug(psum);

    int lo = 0, hi = (int)zeros.size() - 2, mid, res = n;

    while(lo <= hi){
        bool ok = false;
        mid = lo + (hi - lo) / 2;
        // calculate the number of 0's  between these many 1's
        for(int i = 0; i + mid + 1 < (int)zeros.size(); ++ i){
            int L = zeros[i] + 1;
            int R = zeros[i + mid + 1] - 1;
            int ones_inside = psum[R + 1] - psum[L];
            int ones_outside = psum[n] - ones_inside;

            if(ones_outside <= mid){
                ok = true;
            }
        }

        if(ok){
            hi = mid - 1;
            res = mid;
        }
        else lo = mid + 1;
    }

    cout << res << endl;

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