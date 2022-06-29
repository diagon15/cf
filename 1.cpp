// problem link:
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio    ios_base::sync_with_stdio(false);

void yes() { cout << "YES" << "\n"; return; }
void no() { cout << "NO" << "\n"; return; }
template<typename T> void pnl(T a) { cout << a << "\n"; return; }
// #define ONLINE_JUDGE 1221

// #ifndef ONLINE_JUDGE
#define debug(x) cout<<#x<<" "; (_print(x)); cout<<"\n";
// #else
// #define debug(x)
// #endif

void _print(int x) { cout << x; }
void _print(long long x) { cout << x; }
void _print(char x) { cout << x; }
void _print(string x) { cout << x; }
void _print(bool x) { cout << x; }
void _print(size_t x) { cout << x; }

void _print(pair<int, int> x) { _print("{"); _print(x.first); _print(","); _print(x.second); _print("}\n"); }
void _print(pair<long long, long long> x) { _print("{"); _print(x.first); _print(","); _print(x.second); _print("}\n"); }
void _print(pair<string, string> x) { _print("{"); _print(x.first); _print(","); _print(x.second); _print("}\n"); }

template<class T> void _print(vector<T> v) { cout << "[";     for (T i : v) _print(i), _print(' ');      cout << "]"; }
template<class T> void _print(set<T> v) { cout << "[";     for (T i : v) _print(i), _print(' ');      cout << "]"; }
template<class T> void _print(multiset<T> v) { cout << "[";     for (T i : v) _print(i), _print(' ');      cout << "]"; }

vector<char>adj[26];
int visited[26];

int num;
string ans;

bool dfs(int idx) {

    // for(int i = 0; i < visited[idx].size(); i++){
    //     if(visited[i] == num)
    // }
    // if(visited[i].back() ==) // oh no, coz the visited[idx] wil == num as viisted list will be recently updated with num only.
    // debug(ans);

    if (visited[idx] == num) return false;
    visited[idx] = num;
    ans += ('a' + idx);
    for (auto& u : adj[idx]) {
        int idxc = u - 'a';
        if (!dfs(idxc)) return false;
    }

    return true;
}

void testcase(int test) { // testcasesid

    int n;
    cin >> n;
    vector<string>v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    bool smallppl[26];
    memset(smallppl, true, sizeof smallppl);


    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            bool flag = true;
            for (int k = 0; k < min(v[i].size(), v[j].size()); ++k) {
                if (v[i][k] != v[j][k]) {
                    int idx = v[i][k] - 'a';
                    adj[idx].push_back(v[j][k]);
                    smallppl[v[j][k] - 'a'] = false;
                    flag = false;
                    break;
                }
            }
            if (flag and v[i].size() > v[j].size()) return pnl("Impossible");
        }
    }

    for(int i = 0; i < 26; ++ i){
        sort(adj[i].begin(), adj[i].end());
        cout << static_cast<char>(i +  97) << " ";
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
        for(auto ch: adj[i]) cout << ch <<" "; cout << endl;
    }

    for (int i = 0;i < 26; i++) {
        num = i + 1;
        if (smallppl[i]) {
            if (!dfs(i))
            ;
            // return pnl("Impossible");
        }
    }
    map<char, int>mp;
    for (int i = 0; i < ans.size(); i++) {
        mp[ans[i]] = 1;
    }
    // debug(ans);

    // for(char i= 'a'; i <= 'z'; i++){
    //     if(mp[i] != 1) ans +=i;
    // }
    // debug(ans);
    // if (ans.size() != 26) return pnl("Impossible");
    cout << ans << endl;

    return;
}

int main() {

    fastio;
    int test = 1, z = 1;
    // cin>>test;
    while (z <= test) {
        testcase(z); z++;
    }

    return 0;
}
/*
for std::lcm use -std=c++17 to compile locally

topics:

bcdefghijklmnopqrsatuvwxyz
asbcdefghijklmnopqrstuvwxyz

abcdefghijklmnopqrstuvwxyz
abcdefghijklmnopqrstuvwxyz

*/