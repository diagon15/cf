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


int solve(int idx, int d, int n, vector<int>& v, vector<int>& arr,int cnt){
    if(arr[idx] == 0)   return 0;
    if(v[idx] != -1) return v[idx];
    if(cnt == n + 4) return v[idx] = - (n + 4);
    v[idx] = 1 + solve((idx + d) % n, d, n, v, arr, cnt + 1);
    return v[idx];
}

void testcase(int test){ // testcasesid

    int n, d;
    cin >> n >> d;
    vector<int> arr(n);
    int has0 = 0;
    for(int i= 0; i < n; ++ i) cin >> arr[i], has0 |= (!arr[i]);

    if(!has0) return pnl(-1);

    if(n%d == 0){
        int one = 0;
        for(int i = 0; i < d; ++ i){
            int res = 1;
            for(int j = i; j < n; j += d){
                res &= arr[j];
            }
            one |= res;
        }
        if(one) return pnl(-1); // 1 remains
    }

    vector<int>v(n, -1);
    for(int i = 0; i < n; ++ i){
        if(arr[i] == 0) v[i] = 0;
        else if(v[i] == -1){
            // debug(i);
            v[i] = 1 + solve((i + d)%n, d, n, v, arr, 1);
        }
    }


    int ans = *max_element(v.begin(), v.end());

    cout << ans << endl;


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