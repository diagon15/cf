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


void testcase(int test){ // testcasesid

    int n;
    cin >> n;
    ll x, y, u, v;
    map<pair<ll,ll>, ll>mp;
    ll pos = 0, neg = 0, pos2 = 0, neg2 = 0;
    for(int i = 0; i < n; ++ i){
        cin>> x >> y >> u >> v;
        ll dy = v - y;
        ll dx = u - x;
        // int s1 = dy/abs(dy), s2 = dx/abs(dx);
        // dy =abs(dy);
        // dx =abs(dx);
        // cout << "{"<< dx <<","<<dy<< "}\n";
        ll g = abs(__gcd(dx, dy));
        dy/= g;
        dx/= g;
        // debug(g);
        // cout << "{"<< dx <<","<<dy<< "}\n";
        // int sign = s1*s2;
        // ++ mp[{sign*dx, dy}];
        if(dx == 0){
            if(dy > 0) ++pos;
            else ++neg;
        }
        else if(dy == 0){
            if(dx > 0) ++pos2;
            else ++ neg2;
        }
        else
            ++ mp[{dx, dy}];
    }

    string encrypt(string word1) {
        int n = word1.size();
        string res = "";
        for(int i = 0; i < n; ++ i){
            if(mp.find(word1[i]) != mp.end()){
                res += values[mp[word1[i]]];
            }
        }
        return res;
    }

    // int decrypt(string word2, int index = 0, Trie* p = NULL) {
    int decrypt(string word2) {
    /*
        if(index == 0) p = t;
        if(index >= word2.size() and p->endofstr == true) return 1;
        if(index >= word2.size()) return 0;
        if(p == NULL) return 0;
        int res = 0;
        string str = word2.substr(index, 2);
        for(auto &u: mp2[str]){
            int idx = u - 'a';
            if(p->next[idx] != NULL){
                res += decrypt(word2, index + 2, p-> next[idx]);
            }
        }
    }
    ans += pos*neg + pos2 * neg2;
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