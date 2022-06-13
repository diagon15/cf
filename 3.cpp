// problem link:https://codeforces.com/contest/1032/problem/C
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

void _print(pair<int, int> x) { cout << x.first << "," << x.second; }
// void _print(pair<int,int> x) { _print("{"); _print(x.first); _print(","); _print(x.second); _print("}\n"); }
void _print(pair<long long,long long> x) { _print("{"); _print(x.first); _print(","); _print(x.second); _print("}\n"); }
void _print(pair<string,string> x) { _print("{"); _print(x.first); _print(","); _print(x.second); _print("}\n"); }

template<class T> void _print(vector<T> v){    cout<< "[";     for(T i: v) _print(i), _print(' ');      cout<<"]";      }
template<class T> void _print(set<T> v){    cout<< "[";     for(T i: v) _print(i), _print(' ');      cout<<"]";      }
template<class T> void _print(multiset<T> v){    cout<< "[";     for(T i: v) _print(i), _print(' ');      cout<<"]";      }


#define debug(x)    cout<<#x<<" "; (_print(x)); cout<<"\n";
// #define debug(x)


void testcase(int test){ // testcasesid

    int n;
    cin >> n;
    int arr[n + 1];

    for(int i = 1; i <= n; ++ i) cin >> arr[i];
    int f[n + 1][6]{};
    int pre[n + 1][6]{};
    for(int i = 1; i <= 5; ++ i) f[1][i] = 1;

    for(int i = 2; i <= n; ++ i){
        if(arr[i] == arr[i - 1]){
            for(int j = 1; j <= 5; ++ j) if(f[i - 1][j]){
                for(int k = 1; k <= 5; ++ k){
                    if(j!=k) f[i][k] = 1, pre[i][k] = j;
                }
            }
        }
        else if(arr[i - 1] < arr[i]){
            for(int j =1; j <= 5; ++ j) if(f[i - 1][j]){
                for(int k = j + 1; k <= 5; ++ k) f[i][k] = 1, pre[i][k] = j;
                // break;
            }
        }
        else {
            for(int j = 1; j <= 5; ++ j) if(f[i - 1][j]){
                for(int k = 1; k < j; ++ k) f[i][k] = 1, pre[i][k] = j;
            }
        }
    }

    int ans[n + 1];
    for(int i = 1; i <= 5; ++ i){
        if(f[n][i]){
            int y = i;
            for(int x = n; x > 0; -- x){
                ans[x] = y;
                y = pre[x][y];
            }
            break;
        }
        else if( i == 5) return pnl(-1);
    }

    for(int i =1; i <= n; ++ i) cout << ans[i] << " " ; cout << endl;
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