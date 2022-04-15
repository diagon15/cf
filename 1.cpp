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


typedef struct hline {
    int x1;
    int x2;
    int y;
}hline;

int binary_search(vector<hline>& horizontal, int len){
    int m = horizontal.size();
    int lo = 0, hi = m - 1, mid, res = -1;
    while(lo <= hi){
        mid = lo + (hi - lo ) / 2;
        int len_mid = (horizontal[mid].x2 - horizontal[mid].x1 + 1);
        if(len_mid < len){
            res = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    // cout << res <<endl;
    return m - 1 - res;
}

void testcase(int test){ // testcasesid

    int n, m;
    cin >> n >> m;
    vector<int>vertical(n);

    for(int i = 0; i < n; ++ i) cin >> vertical[i];

    sort(vertical.begin(), vertical.end());
    const int N = 1e9;
    vertical.push_back(N);
    vertical.erase(unique(vertical.begin(), vertical.end()), vertical.end());
    n = vertical.size();
    
    vector<hline> horizontal(m);
    for(int i = 0; i < m; ++ i){
        cin >> horizontal[i].x1 >> horizontal[i].x2 >> horizontal[i].y;
    }

    sort(horizontal.begin(), horizontal.end(),[](const hline &a, const hline &b){
        return (a.x2 - a.x1) < (b.x2 - b.x1);
    });

    int ans = N;

    for(int i = 0; i < n; ++ i){
        int len = vertical[i];

        int cost = binary_search(horizontal, len);
        ans = min(cost + i, ans);
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
*/