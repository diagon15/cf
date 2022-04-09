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
int c = 5;
ll query(ll a,ll b){
    cout << "? " << a << " "<< b << endl;
    cout.flush();
    ll res;
    // cin >> res;
    res = __gcd(a + c, b + c);
    return res;
}
void testcase(int test){ // testcasesid

    ll a, b;
    ll bitpos = 0;


    a = 1<<29;
    ll res , ans = 0;
    while(bitpos < 29){
        a = (1<<29)|(1<<bitpos);
        b = (1<<bitpos);
        b*=2;
        res = query(a,b);
        if((res>>bitpos)&1){
            ans |=(b);
        }
        debug(ans);
        ++ bitpos;
    }

    res = query(1,1);
    ans |= ((1<<29)&res);

    cout << "! " << ans << endl;
    cout.flush();

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