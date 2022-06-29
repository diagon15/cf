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


int N;
struct seg {
    vector<int>a;

    void build(vector<int>& arr, int v, int l, int r) {
        if (l == r) a[v] = arr[l];
        else {
            int mid = l + (r - l) / 2;
            build(arr, 2 * v , l, mid);
            build(arr, 2 * v + 1, mid + 1, r);
            a[v] = min(a[2 * v], a[2 * v + 1]);
        }
    }

    int getmin(int l, int r, int id = 1, int al = 0, int ar = N-1) {
        // if (al > ar) return INT_MAX;
        if(r < al or ar < l) return INT_MAX;
        if (l <= al and ar <= r) return a[id];
        int mid = al + (ar - al) / 2;
        debug(id);
        return min(getmin(l, r, id * 2, al, mid), getmin(l, r, id * 2 + 1, mid + 1, ar));
    }

    seg(vector<int>& arr) //:N(arr.size())
    {
        a = vector<int>(4*N);
        build(arr, 1, 0, (int)arr.size() - 1);
    }
};


void testcase(int test){ // testcasesid

    vector<int>arr{4,5,8,34,2,89,6,3,7,32,6,8};
    N = arr.size();
    seg sg(arr);
    int n = arr.size();
    cout << sg.getmin(n-2, n-1) <<endl;
    // cout << sg.getmin(5,9) <<endl;
    // pnl("dsf");



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