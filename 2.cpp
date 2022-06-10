#include<bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define vecp vector<pair<int,int>>
#define vecc vector<vector<int>>
#define pb push_back
#define fr first
#define sc second
#define fr1(i,a,b) for(int i = a; i < b; i++)
#define fr2(i,a,b) for(int i = a; i >= b; i--)
#define fr3(i,a,b) for(int i = a; i <= b; i++)
#define pr pair<int,int>
#define mod 1000000007
#define mod1 998244353
#define all(v) (v).begin(),(v).end()
#define sz(x) (int)(x).size()
#define ppb pop_back
#define ins insert
//#define int long long

void write(vec &v){
    for(auto i:v)
        cout << i << " ";
    cout << "\n";
}

void read(vec &v){
    for(auto &i:v)
        cin >> i;
}

const int INF = 1e9;
const int64_t INFF = 1e18;
const int N = 1e6+69;
class dsu{
public:
    vec par;
    vec siz;
    vecp red;
    vecp blue;
    dsu(int n){
        par.resize(n);
        siz.resize(n);
        red.resize(n);
        blue.resize(n);
        fr1(i,0,n){
            par[i] = i;
            siz[i] = 1;
            red[i].fr = 0;
            red[i].sc = -1;
            blue[i].fr = 0;
            blue[i].sc = -1;
        }
    }
    int findParent(int v){
        if(v == par[v])
            return v;
        return par[v] = findParent(par[v]);
    }

    
    void dounion(int u,int v){
        u = findParent(u);
        v = findParent(v);
        if(siz[v] > siz[u]){
            swap(u,v);
        }
        siz[u] += siz[v];
        blue[u].fr = min(blue[u].fr,blue[v].fr);
        red[u].fr = min(red[u].fr,red[v].fr);
        blue[u].sc = max(blue[u].sc,blue[v].sc);
        red[u].sc = max(red[u].sc,red[v].sc);
        par[v] = u;
    }
};

void solve(){
    int n;
    cin >> n;
    vector<array<int,3>> sorted;
    dsu d(n);
    fr1(i,0,n){
        int c,l,r;
        cin >> c >> l >> r;
        sorted.pb({l,i + 1,c});
        sorted.pb({r+1,-(i + 1),c});
        if(c == 0){
            d.red[i].fr = l;
            d.red[i].sc = r;
        } else {
            d.blue[i].fr = l;
            d.blue[i].sc = r;
        }
    }
    sort(all(sorted));
    set<int> s[2];
    int ans = n;
    for(auto [l,ind,c]:sorted){
        if(ind > 0){
            if(sz(s[1-c])){
                for(auto j:s[1-c]){
                    d.dounion(ind-1,j);
                    ans--;
                }
                s[1-c].clear();
                s[1-c].insert(d.findParent(ind-1));
                s[c].insert(d.findParent(ind-1));
            } else {
                s[c].insert(d.findParent(ind-1));
            }
        } else {
            ind = abs(ind);
            int par = d.findParent(ind-1);
            if(c == 0){
                if(d.red[par].sc == l-1){
                    if(s[c].count(par)){
                        s[c].erase(par);
                    }
                }
            } else {
                if(d.blue[par].sc == l-1){
                    if(s[c].count(par)){
                        s[c].erase(par);
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    fr3(i,1,t){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}