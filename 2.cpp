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


void testcase(int test){ // testcasesid


    int n;
    cin >> n;
    vector<int> arr(n), brr;
    for(int i = 0; i < n; ++ i) cin >> arr[i];

    auto calc = [&](int &num, int &den) -> void {
        int g = __gcd(num, den);
        num /= g;
        den /= g;
    };

    map<pair<int,int>, int>mp;
    for(int i = 1; i < n; ++ i){
        int numerator = arr[i] - arr[0];
        int denominator = i;
        calc(numerator, denominator);
        ++ mp[{numerator, denominator}];
    }

    int maxi = -1;
    pair<int,int>pr;
    for(auto &u: mp){
        if(maxi < u.second){
            maxi = u.second;
            pr = u.first;
        }
        cout << u.first.first << " "<< u.first.second << " " << u.second <<endl;
        // debug(u.first);
    }
    debug(maxi);
    int idx = 0;
    for(int i = 1; i < n; ++ i){
        int numerator = arr[i] - arr[0];
        int denominator = i;
        calc(numerator, denominator);
        pair<int,int> tmp = {numerator , denominator};
        if(pr != tmp){
            idx = i;
            break;
        }
    }
    bool ok = true;
    // set<pair<int, int>>st;

    debug(idx);
    debug(pr);
    const int ran = -951753486;
    pair<int,int> defaul, slope2 = {- ran, -ran};
    defaul = slope2;

    for(int i = idx + 1; i < n; ++ i){
        int numerator = arr[i] - arr[0];
        int denominator = i;
        calc(numerator, denominator);
        pair<int,int> tmp = {numerator , denominator};
        if(tmp != pr){
            numerator = arr[i] - arr[idx];
            denominator = i - idx;
            calc(numerator, denominator);
            if(slope2 == defaul) slope2 = {numerator, denominator};
            else if(slope2 != pair<int,int>{numerator, denominator}){
                ok = false;
                break;
            }
        }
    }

    // for(int i = 1; i < n; ++ i){
    //     if({arr[i] - arr[0], i} == {pr.first, pr.second}) cout <<"0 "<<i <<endl;
    // }
    // for(int i = idx + 1; i < n; ++ i){
    //     if({arr[i] - arr[idx], i - idx} == slope2) cout << idx <<" "<<i<<endl;
    // }

    if(pr != slope2 and pr.first  and slope2.first) ok = false;

    debug(slope2);
    if(idx == 0) ok = false;
    if(pr.first == 0 or slope2.first == 0) ok = false;
    sort(arr.begin(), arr.end());
    if(arr[(int)arr.size() - 2] == 0) ok = true;
    if(arr[(int)arr.size() - 1] == 0) ok = false;
    ok ? yes(): no();

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