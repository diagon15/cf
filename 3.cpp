// problem link:
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio    ios_base::sync_with_stdio(false);

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

int n, root= - 1;
vector<int>p;

const int N = 2e5 + 1;
vector<int>adjlist[N];
int visited[N];
int vcnt = 1;

void bfs(int node){
    if(visited[node]) return;

    queue<int>q;
    q.push(node);

    while(not q.empty()){
        int tp = q.front();
        q.pop();
        visited[tp] = vcnt;
        for(auto &adjnode: adjlist[tp]){
            if( visited[adjnode] == 0){
                q.push(adjnode);
            }
        }
    }
    ++ vcnt;
}

bool dfs(int node,int cnt){

    if(visited[node] == cnt){
        adjlist[node][0] = node;
        p[node] = node;
        return true;
    }
    if(visited[node] != 0) return false;
    visited[node] = cnt;

    for(auto adjnode: adjlist[node]){
        // if(dfs(adjnode,cnt)) return true;
        dfs(adjnode,cnt);

    }

    return false;
}

void hmm(int old[],int n){
    int ans = 0;

    for(int i = 1; i <= n; ++ i){
        if(p[i] != old[i]) ++ ans;
    }

    cout << ans << endl;
    for(int i = 1; i <= n; ++ i){
        cout << p[i] << " ";
    }
    cout << endl;
}

void testcase(int test){ // testcasesid

    cin >> n;

    p.resize(n + 1);
    int old[n + 1];
    for(int i = 1; i <= n; ++ i) {
        cin >> p[i];
        old[i] = p[i];
        if(p[i] == i) root = i;
    }

    // if(root == -1){
    for(int i = 1; i <= n; ++ i) adjlist[i].push_back(p[i]);// p[i]
    for(int i = 1; i <= n; ++ i){
        dfs(i,i);
    }

    for(int i = 1; i <= n; ++ i) if(p[i] == i) root = i;

    for(int i = 1; i <= n; ++ i){
        if(p[i] == i and i != root){
            p[i] = root;
        }
    }

    hmm(old, n);
    return;



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