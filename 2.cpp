#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
int mod;
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void setIO()
{
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
struct BIT
{
    int n;
    vi bit;
    BIT(int N)
    {
        n = N;
        bit.assign(n + 1,0);
    }
    void update(int i,int v)
    {
        for (;i<=n;i += i & (-i)){
            bit[i] = (bit[i] + v)%mod;
            if (bit[i] < 0)bit[i] += mod;
        }
    }
    int query(int i)
    {
        int ret = 0;
        for (;i>0;i-= i & (-i))ret = (ret + bit[i])%mod;
        return ret;
    }
    void update(int l,int r,int v)
    {
        update(l,v);
        if (r != n)update(r + 1,-v);
    }
};
int main()
{
    // setIO();
    int n,m;
    cin>>n>>m;
    mod = m;
    vector<int> dp(n + 1);
    dp[1] = 1;

    BIT ds(n);

    for (int i = 1;i<=n;i++){
        if (i != 1)dp[i] = ds.query(i);
        ds.update(i + 1,n,dp[i]);

        for (int j = 1;(i * j <= n);j++){
            //update range from i * j to min(n,j * i + j - 1) by +dp[i]
            ds.update(i * j,min(n,j * i + j - 1),dp[i]);
        }

    }
    cout<<dp[n];
    return 0;
}