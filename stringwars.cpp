/********************************/
//                              //
// Code By-                     //
//                              //
// *******        ***           //
//    *          *              //
//    *          *   ***        //
//    * ushar     ***  * upta   //
//                              //
//   aka Algoristy (अल्गोरिस्टी)  //
//                              //
/********************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long int in;
typedef pair<in, in> pii;
typedef vector<in> vi;
typedef vector<vector<in>> vii;
typedef unsigned long long ull;
typedef long double lld;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define loop(i, b) for(in i=0;i<b;i++)
#define dloop(i, a, b) for(in i=a;i<=b;i++)
#define rloop(i,n) for(in i=n-1;i>=0;i--)
#define drloop(i, a, n) for(in i=n;i>=a;i--)
#define pb(a) push_back(a)
#define all(a) a.begin(),a.end()
#define trav(a,b) for(auto &a: b)
#define rtrav(a,b) for (auto a = b.rbegin(); a != b.rend(); a++) //use*a
#define mod1 1000000007
#define mod2 998244353
#define ff first
#define ss second
#define elif else if
#define gcd(a, b) (__gcd((a), (b)))
inline in lcm(in a, in b) {return a / gcd(a, b) * b;}
const in PI = acos((in) - 1);
in powerm(in x, in y, in m) {
    in res = 1; x = x % m; if (x == 0) return 0;
    while (y > 0) {if (y & 1) res = (res * x) % m; y = y >> 1; x = (x * x) % m;} return res;
}
in power(in x, in y) {
    in res = 1; if (x == 0) return 0;
    while (y > 0) {if (y & 1) res = (res * x); y = y >> 1; x = (x * x);} return res;
}
inline in inv(in a, in p = mod1) {return powerm(a, p - 2, p);}
in summ(in a, in b, in m = mod1) {return (a % m + b % m) % m;}
in difm(in a, in b, in m = mod1) {return (a % m - b % m) % m;}
in mulm(in a, in b, in m = mod1) {return (a % m * b % m) % m;}
in divm(in a, in b, in m = mod1) {return mulm(a, inv(b, m), m);}

#ifndef ONLINE_JUDGE
#define debug(bnm) cerr << #bnm <<" "; _print(bnm); cerr << endl
#else
#define debug(bnm)
#endif

void _print(in t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#define MAXN 5000001

in fib[91] = {};

void preSolve(){

    fib[1] = 2;
    fib[2] = 3;

    dloop(i, 3, 90){
        fib[i] = fib[i-1] + fib[i-2];
    }
}

void Solve(in tx){

    in n, m;
    cin>>n>>m;

    if(m > fib[n]){
        cout<<"NO ANSWER"<<endl;
        return;
    }
    else{

        string ans = "";

        while(n > 2){

            if(fib[n-1] >= m){
                ans.pb('A');
                n--;
            }
            else{
                ans.pb('B');
                ans.pb('A');
                m -= fib[n-1];
                n -= 2;
            }
        }
        

        if(n == 1){
            if(m == 1) ans.pb('A');
            else ans.pb('B');
        }
        else{
            if(m == 1) ans += "AA";
            elif(m == 2) ans += "AB";
            else ans += "BA";
        }
        cout<<ans<<endl;
    }

}

int main() {

    fast;
    #ifndef ONLINE_JUDGE
        freopen("Error.tbnmt", "w", stderr);
    #endif

    preSolve();
    for(int i = 0; i <= 10; ++ i) cout << fib[i] << " ";
    cout << endl;
    in t = 1;
    // cin >> t;
    loop(i, t)
        Solve(i);

    return 0;
}