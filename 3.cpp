#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<bool> used(n, false);
        bool fail = false;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (used[i])
                continue;
            int cur = i, pref = 0, last = 0, iter = 0, ans = 0;
            do {
                used[cur] = true;
                if (a[cur] == 0) {
                    ans = max(ans, last);
                    last = 0;
                } else {
                    last++;
                    if (iter == pref) {
                        pref++;
                    }
                }
                cur = (cur + d) % n;
                iter++;
            } while (cur != i);
            if (iter != pref)
                ans = max(ans, pref + last);
            else {
                fail = true;
                break;
            }
            res = max(res, ans);
        }
        if (fail)
            cout << "-1\n";
        else
            cout << res << '\n';
    }
}