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


void testcase(int test){ // testcase

    int n, m;
    cin >> n >> m;
    vector<vector<int>> dest(n, vector<int>(0, 0));
    vector<set<pair<int,int>>> source(n, set<pair<int,int>>());
    set<int>remaining;

    for(int i = 0; i < m; ++ i){
        int start, end;
        cin >> start >> end;
        --start, --end;
        source[start].insert({ (start - end + n)%n , i});
        dest[end].push_back(i);
        remaining.insert(i);
    }

    vector<set<pair<int,int>>>reset_source = source;

    set<int>st;


    for(int startpos = 0; startpos < n; ++ startpos){
        set<int> rem = remaining;
        st = set<int>();
        source = reset_source;
        // return;
        int ans = 0;
        int idx = startpos;
        while(not rem.empty()){

            if(not source[idx].empty()){
                auto chosen = *source[idx].begin();
                st.insert(chosen.second);
                source[idx].erase(chosen);
            }
            // debug(st.size());
            // for(auto u: st) cout << u << " " ; cout << endl;
            for(auto u: dest[idx]){
                if(st.find(u) != st.end()){
                    rem.erase(u);
                    st.erase(u);
                }
            }
            if(rem.size()) ++ ans;
            // debug(rem.size());

            idx = (idx + 1)%n;
        }
        cout << ans << " " ;
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