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

// vector<ll>v;

ll sqroot(ll x){
    ll lo = 1, hi = x, mid;

    while(lo <= hi){
        mid = lo + (hi - lo) / 2;
        ll sqmid = mid * mid;
        if(sqmid == x) return mid;
        else if(sqmid < x) lo = mid + 1;
        else hi = mid - 1;
    }
    return lo;
}

void testcase(int test){ // testcasesid

    ll x;
    cin >> x;
    if(x == 1) return pnl(-1);
    if(x == 0) return pnl("1 1");
    ll n,m;
    ll lo = sqroot(x), hi = 1e9, mid, res= -1, n1;


    ll lower= sqroot(x + 1) - 1, upper = sqroot(4*x/3) + 1;


    for(ll n1 = lower; n1 <= upper; ++ n1){
        ll lo = 2, hi = n1 - 1, m1;
        ll testn = n1 - x;
        ll rtn = sqroot(n1 - x);
        if(rtn - testn) 
        while(lo <= hi){
            m1 = lo + (hi - lo) / 2;
            ll num1s = n1*n1 - (n1/m1)*(n1/m1);

            if(num1s <= x){
                lo = m1 + 1;
            }
            else{
                hi = m1 - 1;
            }
        }
        m1 = lo - 1;

    }





    if(res == -1){
        cout << -1 << endl;
        return ;
    }

    n = res;
    m = n / sqroot(n*n - x);

    cout << n << " " << m << endl;

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
1
21
topics:
*/