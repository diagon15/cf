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


int getans(string s){
    int ans = 0;
    for(int i= 0; i < (int)s.size() - 1; ++ i){
        ans += (s[i] - '0') * 10 + (s[i + 1] - '0');
    }
    return ans;
}

void testcase(int test){ // testcasesid


    int n, k;
    cin >> n >> k;


    string s;
    cin >> s;
    string s2 = s;
    int l0 = -1, r1 = n -1;



    int ans1 = 0, ans2 = 0;
    int tk = k;

    for(int i = 0; i < n; ++ i)    if(s[i] == '1') r1 = i;
    while(tk > 0 and r1 < n - 1){
        -- tk;
        swap(s[r1], s[r1 + 1]);
        ++ r1;
    }
    for(int i = n - 1; i >= 0; -- i)    if(s[i] == '1') l0 = i;
    while(tk > 0 and l0 > 0){
        -- tk;
        swap(s[l0], s[l0 - 1]);
        -- l0;
    }


    ans1 = getans(s);
    s = s2;

    tk = k;
    l0= -1, r1 = n - 1;

    for(int i = n - 1; i >= 0; -- i)    if(s[i] == '1') l0 = i;
    while(tk > 0 and l0 > 0){
        -- tk;
        swap(s[l0], s[l0 - 1]);
        -- l0;
    }
    
    for(int i = 0; i < n; ++ i)     if(s[i] == '1') r1 = i;
    while(tk > 0 and r1 < n - 1){
        -- tk;
        swap(s[r1], s[r1 + 1]);
        ++ r1;
    }

    ans2 = getans(s);

    ans1 = min(ans1, ans2) ;
    cout << ans1 <<endl;

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