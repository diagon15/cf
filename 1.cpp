// problem link:https://codeforces.com/contest/1690/problem/F
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// template <class T>
// using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;
using ull = unsigned long long;
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


void testcase(int test){ // testcasesid

    int n;
    cin >> n;
    string s;
    cin >> s;
    int arr[n];
    for(int i = 0; i < n; ++ i) cin >> arr[i], -- arr[i];

    bool visited[n]{};

    vector<deque<int>>data;

    for(int i = 0; i < n; ++ i){
        if(not visited[i]){
            int idx = i;
            deque<char>dq;
            // vector<char>v;
            set<char>st;
            while(not visited[idx]){
                visited[idx] = true;
                dq.push_back(s[idx]);
                if(st.size() <= 1) st.insert(s[idx]);
                idx = arr[idx];
            }

            if(st.size() == 2){

                while(dq.front() == dq.back()){
                    dq.push_front(dq.back());
                    dq.pop_back();
                }
                // vector<int>u;
                deque<int>uq;
                int cnt = 1;
                for(int i = 1; i < dq.size(); ++ i){
                    if(dq[i] == dq[i - 1]){
                        ++ cnt;
                    }
                    else{
                        uq.push_back(cnt);
                        cnt = 1;
                    }
                }

                uq.push_back(cnt);
                int mini = *min_element(uq.begin(), uq.end());
                int mini_cnt = 0;
                for(auto &e: uq) mini_cnt += (mini == e ? 1 : 0);
                if(mini_cnt != uq.size()){
                    while(mini != uq.front()) uq.push_back(uq.front()), uq.pop_front();
                    while(mini == uq.back()) uq.push_front(uq.back()), uq.pop_back();
                }
                data.push_back(uq);
            }
        }
    }

    sort(data.begin(), data.end());
    data.erase(unique(data.begin(), data.end()), data.end());
    ull ans = 1;
    for(auto &vect: data){
        ull num = accumulate(vect.begin(), vect.end(), 0);
        ans = ans*num; ///__gcd(ans, num);
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