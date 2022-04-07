// problem link:https://codeforces.com/problemset/problem/1580/A
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

const int N = 401;
vector<vector<int>> arr(N, vector<int>(N, 0));
vector<vector<int>> sums(N, vector<int>(N, 0));
string s[N];

int num_1(int y1, int x1, int y2, int x2){
    // cout << y1 << " " << x1 << " " << y2 << " " << x2 << endl;
    return sums[y2][x2] - sums[y2][x1 - 1] - sums[y1 - 1][x2] + sums[y1 - 1][x1 - 1];
}

int num_0(int y1, int x1, int y2, int x2){
    return (y2 - y1 + 1) * (x2 - x1 + 1) - num_1(y1, x1, y2, x2);
}
void pit(){
    for(int i = 0; i < sums.size(); ++ i){
        for(int j = 0; j < sums.back().size(); ++ j){
            cout << sums[i][j] ;
            cout <<"\t";
        }
        cout << "\n";
    }
}
void pit2(vector<vector<int>>& arr){
    for(int i = 0; i < arr.size(); ++ i){
        for(int j = 0; j < arr.back().size(); ++ j){
            cout << arr[i][j] ;
            // cout <<"\t";
        }
        cout << "\n";
    }
}

#define SOME_MAX_VAL 160005
void testcase(int test){ // testcasesid

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; ++ i){
        cin >> s[i];
    }

    sums = arr;

    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            arr[i][j] = s[i][j - 1] == '1';
        }
    }

    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            sums[i][j] = sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1] + arr[i][j];
        }
    }
    // pit();
    // pit2(arr);
    ll ans = SOME_MAX_VAL;
    for(int x1 = 1; x1 <= m; ++ x1){
        for(int x2 = x1 + 3; x2 <= m; ++ x2){
            ll prev_val = SOME_MAX_VAL;
            for(int y = 5; y <= n; ++ y){
                // case1: new reactangle of height = 5
                ll leftvertical = num_0(y - 3, x1, y - 1, x1);
                ll rightvertical = num_0(y - 3, x2, y - 1, x2);
                ll upperhorizontal = num_0(y - 4, x1 + 1, y - 4, x2 - 1);
                ll lowerhorizontal = num_0(y, x1 + 1, y, x2 - 1);
                ll innerbox = num_1(y - 3, x1 + 1, y - 1, x2 - 1);
                ll case1cost = leftvertical + rightvertical + upperhorizontal + lowerhorizontal + innerbox;

                // case2: extend the length by 1 of prev base
                // ll case2cost = prev_val - num_0(y - 1, x1 + 1, y - 1, x2 - 1) + num_0(y - 1, x1, y - 1, x1)
                // + num_0(y - 1, x2, y - 1, x2) + num_1(y, x1 + 1, y, x2 - 1) + num_0(y, x1 + 1, y, x2 - 1);
                ll case2cost = prev_val - num_0(y - 1, x1 + 1, y - 1, x2 - 1) + num_1(y - 1, x1 + 1, y - 1, x2 - 1)
                + num_0(y - 1, x1, y - 1, x1)
                + num_0(y - 1, x2, y - 1, x2)
                + num_0(y, x1 + 1, y, x2 - 1);
                // + num_1(y, x1 + 1, y, x2 - 1)

                ll curr_cost = min(case1cost, case2cost);
                ans = min(curr_cost, ans);
                prev_val = curr_cost;
                // debug(innerbox);
                // cout << case1cost << " "<< case2cost << " " << y << " " << x1 << " " << x2 <<endl;
                // debug(case1cost);
                // debug(ans);
            }
        }
    }

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