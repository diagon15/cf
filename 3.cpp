#define ll long long
#define dd long double
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define mp make_pair
#define mt make_tuple
#define fo(i , n) for(ll i = 0 ; i < n ; i++)
#define tll tuple<ll ,ll , ll>
#define pll pair<ll ,ll>
#include<bits/stdc++.h>
/*#include<iomanip>
#include<cmath>
#include<cstdio>
#include<utility>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<bitset>*/
dd pi = acos(-1) ;
ll z =  1000000007 ;
ll inf = 1e12 ;
ll p1 = 37 ;
ll p2 = 53 ;
ll mod1 =  202976689 ;
ll mod2 =  203034253 ;
ll fact[100] ;
ll gdp(ll a , ll b){return (a - (a%b)) ;}
ll ld(ll a , ll b){if(a < 0) return -1*gdp(abs(a) , b) ; if(a%b == 0) return a ; return (a + (b - a%b)) ;} // least number >=a divisible by b
ll gd(ll a , ll b){if(a < 0) return(-1 * ld(abs(a) , b)) ;    return (a - (a%b)) ;} // greatest number <= a divisible by b
ll gcd(ll a , ll b){ if(b > a) return gcd(b , a) ; if(b == 0) return a ; return gcd(b , a%b) ;}
ll e_gcd(ll a , ll b , ll &x , ll &y){ if(b > a) return e_gcd(b , a , y , x) ; if(b == 0){x = 1 ; y = 0 ; return a ;}
ll x1 , y1 , g; g = e_gcd(b , a%b , x1 , y1) ; x = y1 ; y = (x1 - ((a/b) * y1)) ; return g ;}
ll power(ll a ,ll b , ll p){if(b == 0) return 1 ; ll c = power(a , b/2 , p) ; if(b%2 == 0) return ((c*c)%p) ; else return ((((c*c)%p)*a)%p) ;}
ll inverse(ll a ,ll n){return power(a , n-2 , n) ;}
ll max(ll a , ll b){if(a > b) return a ; return b ;}
ll min(ll a , ll b){if(a < b) return a ; return b ;}
ll left(ll i){return ((2*i)+1) ;}
ll right(ll i){return ((2*i) + 2) ;}
ll ncr(ll n , ll r){if(n < r|| (n < 0) || (r < 0)) return 0 ; return ((((fact[n] * inverse(fact[r] , z)) % z) * inverse(fact[n-r] , z)) % z);}
void swap(ll&a , ll&b){ll c = a ; a = b ; b = c ; return ;}
//ios_base::sync_with_stdio(0);
//cin.tie(0); cout.tie(0);
using namespace std ;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// ordered_set s ; s.order_of_key(val)  no. of elements strictly less than val
// s.find_by_order(i)  itertor to ith element (0 indexed)
//__builtin_popcount(n) -> returns number of set bits in n
ll seed;
mt19937 rnd(seed=chrono::steady_clock::now().time_since_epoch().count()); // include bits

ll get_ans(vector<ll> &v, ll final)
{
    ll ans = v[2] ;
    ans = min(ans , 1 + v[final]) ;
    return ans ;
}


void dfs(vector<ll> adj[] , vector<vector<ll> > &dp , vector<ll> &a, vector<ll> &b, ll u, ll p)
{
    ll c = 0 ;

    dp[u] = {0 , 0 , 0} ;
    if(a[u] != b[u])
        dp[u][2] = inf ;
    fo(i , adj[u].size())
    {
        ll v = adj[u][i] ;
        if(v == p)
            continue ;
        c++ ;
        dfs(adj , dp , a , b , v , u);

        dp[u][0] += dp[v][0] ;
        dp[u][1] += dp[v][1] ;
        dp[u][2] += get_ans(dp[v] , b[v]) ;

    }
    fo(i , 3)
        dp[u][i] = min(dp[u][i] , inf) ;

    if(c != 0)
    {
        dp[u][1-b[u]] = 1 + dp[u][b[u]] ;
        return ;
    }

    if(c == 0)
    {
        if(a[u] == b[u])
        {
            dp[u][1 - a[u]] = 1 ;
        }
        else
        {
            dp[u][2] = inf ;
            dp[u][1 - b[u]] = 1 ;
        }
        return ;
    }
    return ;
}


void solve()
{
    ll n ;
    cin >> n ;
    vector<ll> a(n) , b(n) ;
    fo(i , n)
        cin >> a[i] ;
    fo(i , n)
        cin >> b[i] ;

    vector<ll> adj[n] ;
    fo(i , n-1)
    {
        ll u , v ;
        cin >> u >> v ;
        u-- ; v-- ;
        adj[u].pub(v) ;
        adj[v].pub(u) ;
    }

    vector<vector<ll> > dp(n , vector<ll> (3)) ;
    // dp[i][0] represents min number of moves if the complete subtree of i is white
    // dp[i][1] represents min number of moves if the complete subtree of i is black
    // dp[i][2] represents min number of moves if no operation is done on i^th node

    dfs(adj , dp , a , b , 0 , -1) ;

    // fo(i , n)
    // {
    //     cout << i << ": " << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << endl ;
    // }

    ll ans = get_ans(dp[0] , b[0]) ;
    cout << ans << endl ;
    return ;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt" , "r" , stdin) ;
    freopen("outputf.txt" , "w" , stdout) ;
    freopen("errorf.txt" , "w" , stderr) ;
    #endif

    ll t = 1;
    cin >> t ;

    while(t--)
    {
        solve() ;
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";

    return 0;
}