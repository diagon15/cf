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

void _print(pair<int,int> x) { _print("{"); _print(x.first); _print(","); _print(x.second); _print("}\n"); }
void _print(pair<long long,long long> x) { _print("{"); _print(x.first); _print(","); _print(x.second); _print("}\n"); }
void _print(pair<string,string> x) { _print("{"); _print(x.first); _print(","); _print(x.second); _print("}\n"); }

template<class T> void _print(vector<T> v){    cout<< "[";     for(T i: v) _print(i), _print(' ');      cout<<"]";      }
template<class T> void _print(set<T> v){    cout<< "[";     for(T i: v) _print(i), _print(' ');      cout<<"]";      }
template<class T> void _print(multiset<T> v){    cout<< "[";     for(T i: v) _print(i), _print(' ');      cout<<"]";      }


#define debug(x)    cout<<#x<<" "; (_print(x)); cout<<"\n";
// #define debug(x)

int r = 1e9, col = -1;

void testcase(int test){ // testcasesid

    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0; i < n; ++ i) cin >> arr[i];
    bool jumped = false;
    int ypos = 1, xpos = 1;
    if(arr[0] != 1) return no();

    if(n == 1){
        if(arr[0] == 1) col = 1;
        else return no();
    }

    for(int i = 0; i + 1 < n; ++ i){
        if(arr[i] == arr[i + 1]) return no();

        if(abs(arr[i] - arr[i + 1]) == 1){
            if(not jumped){
                col = max({col, arr[i], arr[i + 1]});
                // debug(col);
            }
            else{
                int num = min(arr[i + 1], arr[i])/col;
                if(num*col < min(arr[i], arr[i + 1]) and max(arr[i], arr[i + 1]) <= (num +1) * col);
                else return no();
            }
            ypos += arr[i + 1] - arr[i];
        }
        else{
            if(not jumped){
                if(arr[i + 1] < arr[i]) return no();
                    // debug(arr[i + 1]);
                    // debug(col);
                    // debug(ypos);
                    // debug(xpos);
                if(col + ypos > arr[i + 1]){
                    return no();
                }
                col =  arr[i + 1] - ypos;
                jumped = true;
                ++ xpos;
            }
            else{
                if(xpos < 1e9 and col*(xpos - 1) + ypos + col == arr[i + 1]){
                    ++ xpos;
                }
                else if(xpos > 1 and col*(xpos - 1) + ypos - col == arr[i + 1]){
                    -- xpos;
                }
                else return no();
            }
        }
    }

    yes();
    cout << (ll)1e9 << " " << col << endl;
    
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

14
1 2 1 5 1 2 3 7 8 12 11 10 6 2

4
1 2 3 5

8
1 2 3 4 5 4 3 7

topics:
*/