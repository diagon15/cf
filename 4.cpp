// problem link:
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios_base::sync_with_stdio(false);

void yes()
{
    cout << "YES"
         << "\n";
    return;
}
void no()
{
    cout << "NO"
         << "\n";
    return;
}
template <typename T>
void pnl(T a)
{
    cout << a << "\n";
    return;
}

void _print(int x) { cout << x; }
void _print(long long x) { cout << x; }
void _print(char x) { cout << x; }
void _print(string x) { cout << x; }
void _print(bool x) { cout << x; }
void _print(size_t x) { cout << x; }

void _print(pair<int, int> x)
{
    _print("{");
    _print(x.first);
    _print(",");
    _print(x.second);
    _print("}\n");
}
void _print(pair<long long, long long> x)
{
    _print("{");
    _print(x.first);
    _print(",");
    _print(x.second);
    _print("}\n");
}
void _print(pair<string, string> x)
{
    _print("{");
    _print(x.first);
    _print(",");
    _print(x.second);
    _print("}\n");
}

template <class T>
void _print(vector<T> v)
{
    cout << "[";
    for (T i : v)
        _print(i), _print(' ');
    cout << "]";
}
template <class T>
void _print(set<T> v)
{
    cout << "[";
    for (T i : v)
        _print(i), _print(' ');
    cout << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cout << "[";
    for (T i : v)
        _print(i), _print(' ');
    cout << "]";
}

#define debug(x)       \
    cout << #x << " "; \
    (_print(x));       \
    cout << "\n";
// #define debug(x)
set<string> st5, st6, stp, st;
vector<string> v;

void solvepal(string p, int l, int r)
{
    if (l > r)
    {
        stp.insert(p);
        return;
    }

    p[l] = '0';
    p[r] = '0';
    solvepal(p, l + 1, r - 1);
    p[l] = '1';
    p[r] = '1';
    solvepal(p, l + 1, r - 1);
    return;
}

void solveall(string p)
{
    if (p.size() == 5 or p.size() == 6)
    {
        st.insert(p);
        if (p.size() == 6)
            return;
    }
    p += "0";
    solveall(p);

    p.pop_back();
    p += "1";
    solveall(p);

    return;
}

void testcase(int test)
{ // testcasesid

    string p = "$$$$$";
    solveall("");
    solvepal(p, 0, 4);
    p += "$";
    solveall("");
    solvepal(p, 0, 5);
    // cout <<"st:\n";
    // for(auto &u: st){
    //     cout <<u << endl;
    // }
    // cout <<"stp:\n";
    // for(auto &u: stp){
    //     cout <<u << endl;
    // }
    set<string> res;
    set_difference(st.begin(), st.end(), stp.begin(), stp.end(), inserter(res, res.end()));
    pnl(res.size());
    for (auto &u : res)
    {
        cout << u << endl;
    }
    // auto it = set_difference(st.begin(), st.end(), stp.begin(), stp.end(), v.begin());
    // v.resize(it - v.begin());
    // cout << v.size() << endl;
}

int main()
{
    fastio;
    int test = 1, z = 1;
    // cin>>test;
    while (z <= test)
    {
        testcase(z);
        z++;
    }
    return 0;
}
/*
for std::lcm use -std=c++17 to compile locally

g++ *.cpp > log.txt 2>&1

topics:
*/

// problem link:
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios_base::sync_with_stdio(false);

void yes()
{
    cout << "YES"
         << "\n";
    return;
}
void no()
{
    cout << "NO"
         << "\n";
    return;
}
template <typename T>
void pnl(T a)
{
    cout << a << "\n";
    return;
}

void _print(int x) { cout << x; }
void _print(long long x) { cout << x; }
void _print(char x) { cout << x; }
void _print(string x) { cout << x; }
void _print(bool x) { cout << x; }
void _print(size_t x) { cout << x; }

void _print(pair<int, int> x)
{
    _print("{");
    _print(x.first);
    _print(",");
    _print(x.second);
    _print("}\n");
}
void _print(pair<long long, long long> x)
{
    _print("{");
    _print(x.first);
    _print(",");
    _print(x.second);
    _print("}\n");
}
void _print(pair<string, string> x)
{
    _print("{");
    _print(x.first);
    _print(",");
    _print(x.second);
    _print("}\n");
}

template <class T>
void _print(vector<T> v)
{
    cout << "[";
    for (T i : v)
        _print(i), _print(' ');
    cout << "]";
}
template <class T>
void _print(set<T> v)
{
    cout << "[";
    for (T i : v)
        _print(i), _print(' ');
    cout << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cout << "[";
    for (T i : v)
        _print(i), _print(' ');
    cout << "]";
}

#define debug(x)       \
    cout << #x << " "; \
    (_print(x));       \
    cout << "\n";
// #define debug(x)

vector<string> v;
set<string> npal;

void testcase(int test)
{ // testcasesid

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<int>> dp(n, vector<int>(2, 0));
    for (int i = 0; i < 4; ++i)
    {
        if (s[i] == '?')
        {
            dp[i][0] = 1;
            dp[i][1] = 1;
        }
        else if (s[i] == '1')
            dp[i][1] = 1;
        else if (s[i] == '0')
            dp[i][0] = 1;
    }

    for (int i = 4; i < n; ++i)
    {

        dp[i][0] = 0;
        dp[i][1] = 0;

        for (auto &u : npal)
        {
            int m = u.size();
            // cout << u << endl;
            // vector<int>arr(m); for(int k = 0; k < m; ++ k) arr[k] = (u[k] - '0');
            if (i - m + 1 >= 0 and ((s[i] == '?') or (s[i] == u.back())))
            {

                int valid = 1;

                for (int j = 0; j < m - 1; ++j)
                {
                    valid &= dp[i - m + j + 1][u[j] - '0'];
                    // if(dp[i][arr[m - 1]] == 0) break;
                }
                if (valid and i == n - 1)
                    cout << u << endl;
                dp[i][u.back() - '0'] |= valid;
            }
        }
    }

    bool ok = false;
    ok = (s.back() == '?' ? dp[n - 1][0] | dp[n - 1][1] : dp[n - 1][s.back() - '0'] == 1);
    // if(dp[n - 1][s.back() - '0']) ok = true;

    for (int i = 0; i < n; ++i)
        cout << dp[i][0];
    cout << "\n";
    for (int i = 0; i < n; ++i)
        cout << dp[i][1];
    cout << "\n";

    string ans = "IMPOSSIBLE";
    if (ok)
        ans = "POSSIBLE";

    cout << "Case #" << test << ": " << ans << endl;

    return;
}
set<string> st5, st6, stp, st;
// vector<string> v;

void solvepal(string p, int l, int r)
{
    if (l > r)
    {
        stp.insert(p);
        return;
    }

    p[l] = '0';
    p[r] = '0';
    solvepal(p, l + 1, r - 1);
    p[l] = '1';
    p[r] = '1';
    solvepal(p, l + 1, r - 1);
    return;
}

void solveall(string p)
{
    if (p.size() == 5 or p.size() == 6)
    {
        st.insert(p);
        if (p.size() == 6)
            return;
    }
    p += "0";
    solveall(p);

    p.pop_back();
    p += "1";
    solveall(p);

    return;
}

int32_t main()
{
    fastio;
    string p = "$$$$$";
    solveall("");
    solvepal(p, 0, 4);
    p += "$";
    solveall("");
    solvepal(p, 0, 5);

    set_difference(st.begin(), st.end(), stp.begin(), stp.end(), inserter(npal, npal.end()));
    // pnl(npal.size());

    int test = 1, z = 1;
    cin >> test;
    while (z <= test)
    {
        testcase(z);
        z++;
    }
    return 0;
}
/*
for std::lcm use -std=c++17 to compile locally

g++ *.cpp > log.txt 2>&1

topics:
*/