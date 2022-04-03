#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl cout<<"\n";
#define M 1000000
#define fastio    ios_base::sync_with_stdio(false);


void yes(){ cout<<"YES"<<"\n"; return ;}
void no(){ cout<<"NO"<<"\n"; return ;}
template<typename T> void p(T a){ cout<<a<<" "; return;}
template<typename T> void pnl(T a){ cout<<a<<"\n"; return;}

#define f(i, a) for (int i=0; i<(a); i++)
#define ff(i, a) for (int i=1; i<=(a); i++)
#define fr(i, a) for (int i=(a-1);i>=0;i--)
#define ffr(i, a) for (int i=(a);i>0;i--)

#define trav(a,x) for (auto& a : x)
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define scf(a) scanf("%d",&a)
#define scfll(a) scanf("%lld",&a)

const int ten4=1e4;
const int ten5=1e5;
const int ten6=1e6;
const int ten7=1e7;
const int ten9=1e9;
const int mod = 1e9+7;

struct pair_hash {  //  unordered_set<pair<int,int>,pair_hash>st;    // pair doesn't support hashing, so modify this function for unordered_set pair hash function
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

ll bin_to_integer(string strin){
    ll r=1,sum=0;
    for(ll i=strin.length()-1;i>=0;i--){
        if(strin[i]=='1')    sum+=r;
        r*=2;
    }   return sum;
}
string to_binary(int n){
    string strng;
    while(n>0){
        if(n&1) strng+='1'; else    strng+='0';  n>>=1;
    }
    reverse(strng.begin(),strng.end());
    // int len=66-s.length(); string sn; for(int i=0;i<len;i++){     if(i<len) sn+='0'; } sn+=s;
    return strng;
    // return sn;   // this returns the binary string with length 66 irrespective of n
}

int compare(const void *a, const void *b){
    const ll* x=(ll*) a;
    const ll* y=(ll*) b;
    if(*x>*y) return 1;         // (a,n,sizeof(ll),compare);
    else if(*x<*y) return -1;
    return 0;
}

// _________________________________________________________________________________________________
int power(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=(res*1LL*a)%mod;
        n/=2;
        a=(a*1LL*a)%mod;
    }
    return res;
}
const int Nc=200001;  //
int F[Nc]; // don't use this to get the factorial without using nCr functions first !!!
bool Fcomputed=false;
int nCr(int n,int r){
    if(!Fcomputed){ F[0]=1, Fcomputed=true;     for(int i=1;i<Nc;i++) F[i]=(F[i-1]*1LL*i)%mod;  }
    if(n<r) return 0;
    int res =F[n];
    res= res*1LL*power(F[r],mod-2)%mod;
    res=res*1LL*power(F[n-r],mod-2)%mod;
    return res;
}
// _________________________________________________________________________________________________


struct unionfind{
	vector<int> p;
	unionfind(int N){
		p = vector<int>(N, -1);
	}
	int root(int x){
		if (p[x] < 0){
			return x;
		} else {
			p[x] = root(p[x]);
			return p[x];
		}
	}

	bool same(int x, int y){
		return root(x) == root(y);
	}
	void unite(int x, int y){
		x = root(x);
		y = root(y);
		if (x != y){
			if (p[x] < p[y]){
				swap(x, y);
			}
			p[y] += p[x];
			p[x] = y;
		}
	}
};

void Not_wishfully_matched_to_recieve(vector<int>&v2,int *a, int n){
    map<int,int>mp;
    for(int i = 1; i <= n; i++){
        mp[a[i]] ++;
    }
    for(int i = 1; i <= n; i++){
        if(mp.find(i) == mp.end()){
            v2.push_back(i);
        }
    }
    return;
}

void Not_wishfully_matched_to_give(vector<int>&v1,vector<int>&v2,int *a, int n){

    map<int,int>present_in_v2;
    for(int i = 0; i < v2.size(); i++) present_in_v2[v2[i]] = 1;
    vector<int>present_v2;
    for(int i = 1; i <= n; i++){
        if(mp[a[i]] > 1){
            if(present_in_v2[i]){
                present_v2.push_back(i);
            }
            else{

            }
        }
    }

}

void Edge_case_of_size_one(vector<int>&v1,vector<int>&v2,int *a,int n){
    // i) v1[0] == v2[0] ==>  we need to remove a wishfully matched
    // ii) else match them unwishfully. v1[0] -> v2[0];
}
void testcase(int test){ // testcasesid

    int n;
    cin>>n;
    int a[n+1];
    for(int i = 0; i < n; i++){
        cin>>a[i+1];
    }

    if(n <= 1){
        cout<<0<<endl;
        if(n == 1) cout<<arr[1]<<endl;
        return;
    }

    map<int,int>mp; // <a,b> a is matched to b
    vector<int>v2;
    Not_wishfully_matched_to_recieve(v2,a,n);

    vector<int>v1;
    Not_wishfully_matched_to_give(v1,v2,a,n); // with the help of v2, minimises the collision of removal of i'th map when v2 contains i

    // edge case1: only one is not wishfully matched -
    if(v1.size() == 1 and v2.size() == 1){
        Edge_case_of_size_one(v1,v2,a,n);
        // Map_them(v1,v2,a,n); // done
    }
    else{
        vector<int>vc;
        Max_common_subset_from_v1_v2(v1,v2,vc);

        // edge case2: vc size == 1 -> then easy
        if(vc.size() == 1){
            Map_them2();
        }
        else{
            vector<int>v11,v22;
            vi_minus_vc(v1,vc,v11);
            vi_minus_vc(v2,vc,v22);
            Map_them3();
        }
    }




    // cout << "Case #" << test << ": " << ans << endl;
    return;
}
// https://codeforces.com/problemset/problem/1530/D  1hr 30 min spent  on this problem
int main(){
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


*/