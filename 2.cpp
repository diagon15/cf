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


vector<string>vs;
int si = -1, sj = -1;

int x[]{ 1, 0, 0, -1 };
int y[]{ 0, -1, 1, 0 };
char op[]{ 'D', 'L', 'R', 'U' };


void testcase(int test){ // testcasesid

    int n, m, k;
    cin >> n >> m >> k;

    vs = vector<string>(n, string());

    for (int i = 0; i < n; ++i) {
        cin >> vs[i];
    }


    if (k & 1) return pnl("IMPOSSIBLE");


    for (int i = 0; i < n and si == -1; ++i) {
        for (int j = 0; j < m and si == -1; ++j) {
            if (vs[i][j] == 'X') {
                si = i, sj = j;
            }
        }
    }

    string ans = "";
    map<pair<int, int>, int>path;
    map<pair<int,int>, bool>visited;
    map<pair<int,int>, pair<int,int>>track;
    auto bfs = [&](int a, int b,int dis) -> void {
        queue<array<int,3>>q;

        q.push(array<int,3>{a,b, dis});
        visited[{a, b}] = true;
        track[{a,b}] ={a,b};

        while(not q.empty()){
            array<int, 3> ar = q.front();
            q.pop();
            int a = ar[0], b = ar[1], dis = ar[2];
            path[{a,b}] = dis;
            for(int z = 0; z < 4; ++ z){
                int aa = a + x[z];
                int bb = a + y[z];

                if (aa < 0 or aa >= n or bb < 0 or bb >= m or vs[aa][bb] == '*' or visited[{aa, bb}]) continue;
                visited[{aa, bb}] = true;
                track[{aa, bb}] = {a,b};
                q.push(array<int,3>{aa,bb, dis + 1});
            }
        }
    };

    bfs(si, sj, 0);

    int i = si, j = sj;
    int dist = 0, disp = 0;
    int prvi= -1, prvj= -1;
    int toggle = true;
    while(true){
        if(path[{i,j}] == (k - (int)ans.size())) break;
        int pi = i;
        int pj = j;
        bool yep = false;

        for(int z = 0; z < 4; ++ z){
            int ii = i + x[z];
            int jj = j + y[z];

            if (ii < 0 or ii >= n or jj < 0 or jj >= m or vs[ii][jj] == '*') continue;

            i = ii;
            j = jj;
            ans += op[z];
            ++ dist;
            ++ disp;
            yep = true;
            break;
        }
        if(not yep) return pnl("IMPOSSIBLE");

        if(i == prvi and j == prvj){
            if(toggle)  -- disp;
            toggle = 1 - toggle;
        }

        prvi = pi;
        prvj = pj;
    }
    // debug(ans);

    int rem = k - (int)ans.size();
    // string str = ans.substr((int)ans.size() - rem, rem);
    string str = ans.substr(0, rem);
    reverse(str.begin(), str.end());
    // str.replace()

    for(auto &u: str){
        if(u == 'L') u = 'R';
        else if(u == 'R') u = 'L';
        else if(u == 'D') u = 'U';
        else u = 'D';
    }

    debug(ans);
    // ans = ans + str;
    while(ans.size() != k){
        pair<int,int> nxt = track[{i, j}];
        if(nxt.first == i){
            if(nxt.second == j + 1) ans += "R";
            else ans += "L";
        }
        else{
            if(nxt.first == i + 1) ans += "D";
            else ans += "U";
        }
        i = nxt.first;
        j = nxt.second;
    }

    cout << ans << endl;

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