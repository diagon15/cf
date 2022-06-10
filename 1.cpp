#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define fastio    ios_base::sync_with_stdio(false);
#define endl "\n";

template<typename T> void pnl(T a){ cout<<a<<"\n"; return;}


#define debug(x)    cout<<#x<<" "; (_print(x)); cout<<"\n";
// #define debug(x)

vector<pair<int, int>>blue1, red1, blue2, red2;
map<pair<int,int>, bool> bvis, rvis;

void dfs(pair<int, int>& segment,int isblue);

void bsearch(vector<pair<int, int>> & vect1, vector<pair<int, int>> &vect2, pair<int, int>&segment, int blue){

    // debug(blue);
    // return ;
    int lo = 0, hi = (int)vect2.size() - 1, mid, ptr_start = -1, ptr_end = -2;
    while(lo <= hi){
        mid = lo + (hi - lo) / 2;
        if(segment.first <= vect2[mid].second)  ptr_start = mid,    hi = mid - 1;
        else lo = mid + 1;
    }
    lo = 0, hi = (int) vect2.size() - 1;
    while(lo <= hi){
        mid = lo + (hi - lo) / 2;
        if(vect2[mid].first <= segment.second)    ptr_end = mid,    lo = mid + 1;
        else hi = mid - 1;
    }
    // cout << "ptr_start " << ptr_start << " ptr_end: " << ptr_end << endl;
    while(ptr_start <= ptr_end){
        dfs(vect2[ptr_start], blue^1);
        ++ ptr_start;
    }
    return ;

    ptr_start = -1, ptr_end = -2;
    lo = 0, hi = (int)vect1.size() - 1;
    while(lo <= hi){
        mid = lo + (hi - lo) / 2;
        if(segment.first <= vect1[mid].first) ptr_start = mid, lo = mid - 1;
        else hi = mid + 1;
    }
    lo = 0, hi = (int) vect1.size() - 1;
    while(lo <= hi){
        mid = lo + (hi - lo) / 2;
        if(vect1[mid].first <= segment.second) ptr_end = mid, hi = mid + 1;
        else lo = mid - 1;
    }
    while(ptr_start <= ptr_end){
        dfs(vect1[ptr_start], blue^1);
        ++ ptr_start;
    }
}



void dfs(pair<int, int>& segment,int isblue){
    if(isblue){
        if(bvis[segment]) return ;
        bvis[segment] = true;
        bsearch(red1, red2, segment, isblue);
    }
    else{
        if(rvis[segment]) return ;
        rvis[segment] = true;
        bsearch(blue1, blue2, segment, isblue);
    }
}


void testcase(int test){ // testcasesid

    int n;
    cin >> n;
    for(int i = 0; i < n; ++ i){
        int start, end, color;
        cin >> color >> start >> end;
        if(color){
            blue1.push_back({start, end});
        }
        else{
            red1.push_back({start, end});
        }
    }

    sort(blue1.begin(), blue1.end(), [](const auto &a, const auto &b){ return a.first < b.first;});
    sort(red1.begin(), red1.end(), [](const auto &a, const auto &b){ return a.first < b.first; });

    blue2 = blue1;
    red2 = red1;
    sort(blue2.begin(), blue2.end(), [](const auto &a, const auto &b){ return a.second < b.second;});
    sort(red2.begin(), red2.end(), [](const auto &a, const auto &b){ return a.second < b.second; });

    int cnt = 0;

    for(auto &u: blue1){
        if(not bvis[u]){
            ++ cnt;
            dfs(u, 1);
        }
    }
    for(auto &u: red1){
        if(not rvis[u]){
            ++ cnt;
            dfs(u, 0);
        }
    }

    cout << cnt << endl;

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