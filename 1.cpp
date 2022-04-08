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


template <typename T = int>
class FenwickTree
{
private:
    int getNext(int i)
    {
        return i + (i & (-i));
    }
    int getParent(int i)
    {
        return i - (i & (-i));
    }

public:
    vector<T> data;
    FenwickTree(){};
    FenwickTree(int n) : data(n + 1, 0) {}

    void init()
    {
        for (int i = 1; i < data.size(); ++i)
        {
            int j = getNext(i);
            if (j < data.size())
                data[j] += data[i];
        }
    }

    T getPrefix(int i)
    {
        T sum = data[0];
        for (; i > 0; i = getParent(i))
            sum += data[i];
        return sum;
    }

    void update(int i, T delta)
    {
        for (; i < data.size(); i = getNext(i))
        {
            cout << i << " ";
            data[i] += delta;
        }
    }
};

void pit(FenwickTree <int>f[]){
    cout <<"hello\n";
    for(int i = 0; i < 3; ++ i){
        for(int j = 0; j < f[i].data.size(); ++ i){
            cout << f[i].data[j] << " ";
        }
        cout << endl;
    }
    return ;
}

void testcase(int test){ // testcasesid

    int n;
    cin >> n;
    int m = 2*n + 1;
    FenwickTree<int> f[3] = {FenwickTree<int>(m), FenwickTree<int>(m), FenwickTree<int>(m)};
    pit(f);

    string s;
    cin >> s;
    int sum = 0,ans = 0;

    for(int i = 0; i < n; ++ i){
        sum += (s[i] == '+' ? 1 :  -1);
        f[(sum%3 + 3)%3].update(n + sum, 1);
        ans += f[(sum%3 + 3)%3].getPrefix(n + sum); // - 0 = same

        pit(f);
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