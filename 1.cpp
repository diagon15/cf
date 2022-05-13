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

void pit(deque<char>dq){
    while(not dq.empty()){
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << endl;
}

void testcase(int test){ // testcasesid

    string s;
    cin >> s;

    int zeros = 0, ones_popped = 0;
    for(int i = 0; i < s.length(); ++ i) zeros += (s[i] == '0' ? 1 : 0);

    deque<char>dq;
    for(char ch: s){
        dq.push_back(ch);
    }
    while(not dq.empty() and dq.back() == '0') dq.pop_back(), -- zeros;
    while(not dq.empty() and dq.front() == '0') dq.pop_front(), -- zeros;

    int ans = zeros;
    int left = 0, right = 0;
    // pit(dq);
    while(not dq.empty()){
        if(left < right){
            dq.pop_front();
            ++ left;
        }
        else if(left > right){
            dq.pop_back();
            ++ right;
        }
        else{
            dq.pop_front();
            dq.pop_back();
            ++ left;
            ++ right;
        }

        if(not dq.empty() and dq.back() == '0' and dq.front() == '0' and left == right){
            int z1 = 0, z2 = 0;
            while(not dq.empty() and dq.front() == '0') dq.pop_front(), ++ z1;
            while(not dq.empty() and dq.back() == '0') dq.pop_back(), ++ z2;
            if(z1 > z2){
                ones_popped += left;
                left = 0;
                zeros -= z1;
                ans = min(ans, max(ones_popped, zeros));
            }
            else{
                ones_popped += right;
                right = 0;
                zeros -= z2;
                ans = min(ans, max(ones_popped, zeros));
            }
        }
        else if(not dq.empty() and dq.front() == '0' and left <= right){
            while(not dq.empty() and dq.front() == '0') dq.pop_front(), -- zeros;
            ones_popped += left;
            left = 0;
            ans = min(ans, max(ones_popped, zeros));
        }
        else if(not dq.empty() and dq.back() == '0' and left >= right){
            while(not dq.empty() and dq.back() == '0') dq.pop_back(), -- zeros;
            ones_popped += right;
            right = 0;
            ans = min(ans, max(ones_popped, zeros));
        }

        else {
            ans = min(ans, max(ones_popped + min(left, right), zeros));
        }
        // pit(dq);

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