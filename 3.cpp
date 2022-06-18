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


void testcase(int test){ // testcasesid

    int n;
    cin >> n;
    if(n == 1) return pnl("1\n1");
    if(n&1) return pnl(-1);
    int h = __lg(n);
    int N = 1<<(h+1); -- N;
    vector<pair<int, int>>ans(n);
    for(int i = 1; i <= n; ++ i){
        ans[i - 1].first = i;
    }

    for(int i = n; i > 0; -- i){
        int &ref = ans[i-1].second;
        for(int j = 0; j <= h; ++ j){
            int res = ((i & (1 << j)) ^ (1<<j)) | ref;
            if(res  <= n) ref = res; //, st.insert(ref);
            else break;
        }
        // if(ref == 0) return pnl(-1);
    }

    unordered_set<int>st;
    for(int i = 1; i <= n; ++ i){
        int &ref = ans[i-1].second;
        while(st.count(ref)){
            ref -= (1<<__lg(ref));
        }
        st.insert(ref);
    }

    for(int i = 0; i < n; ++ i){
        if(ans[i].second > n or ans[i].second == 0 ) return pnl(-1);
    }
    // if(st.size() < n) return pnl(-1);

    // cout << ans.size() << endl;
    for(int i = 0; i < n; ++ i) cout << ans[i].first << " " ; cout << endl;
    for(int i = 0; i < n; ++ i) cout << ans[i].second << " " ; cout << endl;


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