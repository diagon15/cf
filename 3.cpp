#include <bits/stdc++.h>
using namespace std;
int lis(int arr[], int n)
{
    const int N = 1e6;
    vector<int>v{ N };
    for (int i = 0; i < n; ++i) {
        //         if(v.empty()) v.push_back(arr[i]);
        auto it = lower_bound(v.begin(), v.end(), arr[i]);
        if (*it == N) *it = arr[i], v.push_back(N);
        else
    }

    return (int)v.size() - 1;

    // Write Your Code here
}

int main(){
    // int arr[]{337};
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++ i) cin >> arr[i];
    cout << lis(arr, n) << endl;
    return 0;
}