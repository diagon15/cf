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

void pit(int x){
    cout << x << endl;
    cout.flush();
}
#define hello cout <<"hello\n";
int read(){
    int x;
    cin >> x;
    return x;
}

void testcase(int test){ // testcasesid

    set<pair<pair<int, int>, pair<int, int>>>sp;
    // sp <bigger against, smaller against>

    set<pair<int, int>>pi;
    // <power, index> -> 2n initial size
    map<int, int>pairs;

    int n, m;
    cin >> n >> m;
    int n2 = 2* n;
    vector<int>v(n + 1);
    for(int i = 1; i <= n2; ++ i){
        int power;
        cin >> power;
        v[i] = power;
        pi.insert({power, i});
    }

    for(int i = 0; i < m; ++ i){
        int f, s;
        cin >> f >> s;
        pairs[f] = s;
        pairs[s] = f;
        if(v[f] < v[s]) swap(f, s);
        sp.insert({{v[f], f}, {v[s], s}});
    }


    int turn ;
    cin >> turn;

    for(auto &u: pi){
        // cout << u.first.first <<","<<u.first.second << " "<< u.second.first <<"," << u.second.second<<endl;
        cout << u.first << " " << u.second << endl;
    }

    if(turn == 1){
        while(not sp.empty()){
            auto useful = *--sp.end();
            pit(useful.first.first);
            pi.erase(useful.first);
            read(); // coz we know it has to be useful.second
            pi.erase(useful.second);
            sp.erase(useful);
        }
        // covered = 2*m;

        while(not pi.empty()){
            auto best = *--pi.end();
            pit(best.first);
            pi.erase(best);
            int your_chance = read();
            pi.erase({v[your_chance], your_chance});
        }
    }
    else{

        while(not pi.empty()){
            int hm = read();
            // pair<int, int> choice = {v[hm], hm};
            // if choice exists in sp
            if(pairs.count(hm)){
                int my_forced_val = pairs[hm];
                pit(my_forced_val);
                pairs.erase(hm);
                pairs.erase(my_forced_val);
                sp.erase({{v[hm], hm}, {v[my_forced_val], my_forced_val}});
                pi.erase({v[hm], hm});
                swap(hm, my_forced_val);
                sp.erase({{v[hm], hm}, {v[my_forced_val], my_forced_val}});
                pi.erase({v[hm], hm});

            }
            else{
                hello;
7
                while (not sp.empty()) {
                    auto useful = *--sp.end();
                    pit(useful.first.second);
                    pi.erase(useful.first);
                    int val = read(); // coz we know it has to be useful.second
                    // pi.erase(useful.second);
                    sp.erase(useful);
                }
                hello;
                // covered = 2*m;
                debug(pi.size());
                return ;
                while (not pi.empty()) {
                    auto best = *--pi.end();
                    pit(best.first);
                    if(pi.size())
                    pi.erase(best);
                    if(pi.empty()) break;
                    int your_chance = read();
                    if(pi.size())
                    pi.erase({ v[your_chance], your_chance });
                }
            }
        }
    }

        cout << pi.size() << endl;

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