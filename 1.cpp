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

int n, m, rk;
vector<string>vs;
int x[]{1, 0, 0, -1};
int y[]{0, -1, 1, 0};
char op[]{'D', 'L', 'R', 'U'};
string ans = "Z";
int si = -1, sj = -1;
bool gotit = false;

void solve(int i, int j, int k, string &str){
    if(k < 0) return ;

    if(k == 0){
        if(si == i and sj == j){
            gotit = true;
            ans = min(ans, str);
        }
        return ;
    }

    for(int z = 0; z < 4; ++ z){
        int ii = i + x[z];
        int jj = j + y[z];

        if(ii < 0 or ii >= n or jj < 0 or jj >= m or vs[ii][jj] == '*') continue;
        str += op[z];
        solve(ii, jj, k - 1, str);
        str.pop_back();
        if(gotit) return ;
    }

    return ;
}


void testcase(int test){ // testcasesid
    cin >> n >> m;

    vs = vector<string>(n, string());

    for(int i = 0; i < n; ++ i){
        cin >> vs[i];
    }

    if(rk&1) return pnl("IMPOSSIBLE");


    for(int i = 0; i < n and si == -1; ++ i){
        for(int j = 0; j < m and si == -1; ++ j){
            if(vs[i][j] == 'X'){
                si = i, sj = j;
            }
        }
    }

    string str = "";
    solve(si, sj, rk, str);
    if(ans == "Z") ans = "IMPOSSIBLE";
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