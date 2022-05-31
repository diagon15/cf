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


void testcase(int test){ // testcasesid
// https://codeforces.com/problemset/problem/1023/D
    int n, q;
    cin >> n >> q;
    int arr[n];
    int any0idx = -1;
    for(int i = 0; i < n; ++ i){
        cin >> arr[i];
        if(arr[i] == 0) any0idx = i;
    }

    int mark[n] = {0};

    int left[q + 1];
    int right[q + 1];
    fill_n(&left[0], q + 1, -1);
    fill_n(&right[0], q + 1, -1);

    for(int i = 0; i < n; ++ i){
        right[arr[i]] = i;
    }
    for(int i = n - 1; i >= 0;  -- i){
        left[arr[i]] = i;
    }
    // map<int, pair<int,int>>mp;

    if(left[q] ==  -1){
        if(any0idx == -1) return no();
        else{
            arr[any0idx] = q;
            left[q] = any0idx;
            right[q] = any0idx;
        }
    }


    while(q){

        int lptr = left[q], rptr = right[q];
        while(lptr < rptr){
            if(arr[lptr] == q or arr[lptr] == 0){
                mark[lptr] = q;
                arr[lptr] = q;
                ++ lptr;
            }
            else if(mark[lptr] > q){
                lptr = right[mark[lptr]] + 1;
            }
            else return no();
        }
            // debug(lptr);
            // debug(rptr);

        if(lptr != rptr) return no();
        mark[rptr] = q;

        -- q;
    }

    for(int i  = 0; i < n; ++ i){
        if(arr[i] == 0) arr[i] = 1;
    }

    yes();
    for(int i = 0; i < n; ++ i){
        cout << arr[i] << " " ;
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