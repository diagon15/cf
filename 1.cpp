// problem link: https://codeforces.com/problemset/problem/917/B?f0a28=1
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
int n, m;
vector<vector<pair<int,char>>>adjlist;

struct Edge {
    int src;
    int dst;
    char ch;
    Edge(int s, int d, char c):src(s), dst(d), ch(c){}
};
// src1 win -> return B, otherwise return A
char solve(int src1, int src2){
    // deque<edge> dq1, dq2;
    char reset = 'a' - 1;
    // debug(reset);
    queue<Edge> q1, q2;
    char max1= reset, max2 = reset;

    for(auto &u: adjlist[src1]){
        q1.push(Edge(src1, u.first, u.second));
        max1 = max(max1, u.second);
    }

    for(auto &u: adjlist[src2]){
        q2.push(Edge(src2, u.first, u.second));
        max2 = max(max2, u.second);
    }

    if(max1 == reset) return 'B';

    while(max2 >= max1 and (not q1.empty()) and (not q2.empty())){
        int q1sz = q1.size();
        int q2sz = q2.size();
        max1 = reset;
        max2 = reset;
        while(q1sz){
            -- q1sz;
            Edge tp = q1.front();
            q1.pop();
            for(auto &u: adjlist[tp.dst]){
                q1.push(Edge(tp.dst, u.first, u.second));
                max1 = max(max1, u.second);
            }
        }

        while(q2sz){
            -- q2sz;
            Edge tp = q2.front();
            q2.pop();
            for(auto &u: adjlist[tp.dst]){
                q2.push(Edge(tp.dst, u.first, u.second));
                max2 = max(max2, u.second);
            }
        }

        if(max1 == reset) return 'B';
    }

    // cout << src1 << " " << src2 << endl;
    if(max2 < max1) return 'A';
    else if(q1.empty()) return 'B';
    else if(q2.empty()) return 'A';
    return 'C'; // never executed
}

void testcase(int test){ // testcasesid

    cin >> n >> m;
    adjlist = vector<vector<pair<int, char>>> (n);
    for(int i = 0; i < m; ++ i){
        int src, dst;
        char ch;
        cin >> src >> dst >> ch;
        -- src, -- dst;
        adjlist[src].push_back({dst, ch});
    }

    char ans[n][n]{'$'};
    for(int max = 0; max < n; ++ max){
        for(int lucas = 0; lucas < n; ++ lucas){
            ans[max][lucas] = solve(max, lucas);
        }
    }


    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < n; ++ j){
            cout << ans[i][j];
        }
        cout << endl;
    }

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