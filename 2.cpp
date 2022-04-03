
#define ll long long
class Solution {
public:
    long long numberOfWays1(string s) {
        int n = s.length();
        ll dp[4][n + 1], dp2[4][n + 1];
        for(int i = 0; i <= n; ++ i) dp[0][i] = 1, dp2[0][i] = 1;
        for(int i = 0; i < 4; ++ i) dp[i][0] = 1, dp2[i][0] = 1;

        string str1 = "$010", str2 = "$101";
        reverse(s.begin(), s.end());
        s+="$";
        reverse(s.begin(), s.end());



        for(int i = 1; i < 4; ++ i){
            for(int j = 1; j <= n; ++ j){
                if(str1[i] == s[j]){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = dp[i - 1][j] +  dp[i][j - 1];
                }

                if(str2[i] == s[j]){
                    dp2[i][j] = dp2[i - 1][j - 1];
                }
                else {
                    dp2[i][j] = dp2[i - 1][j] + dp2[i][j - 1];
                }

            }
        }

        cout << dp[3][n] << endl;
        cout << dp2[3][n] << endl;
        return dp[3][n] + dp2[3][n];

    }

    ll solve(string &s, string str, vector<vector<int>>&dp){
        int n =s.size(), m= str.size();
        if(m == 0) return 1LL;
        if(n == 0) return 0;


        if(s.back() == dp)
    }

    long long numberOfWays(string s) {
        vector<vector<int>>dp(n,vector<int>(3,-1));
        solve(s, "101",dp);
    }
};