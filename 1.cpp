class Solution {
public:

    int l0(int a){
        int cnt = 0;
        while(a > 0 and a%10 == 0) a /= 10, ++ cnt;
        return cnt;
    }

    int f2(int a){
        int cnt = 0;
        while(a > 0 and a%2 == 0) ++ cnt;, a/=2;
        return cnt;
    }
    int f5(int b){
        int cnt = 0;
        while(b > 0 and B%2 == 0) ++ cnt, b /= 2;
        return cnt;
    }

    int maxTrailingZeros(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<pair<int,int>>> horizontal(n, vector<pair<int,int>>(m,{0,0})), vertical;
        vertical = horizontal;

        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                pair<int,int> pr = {f2(grid[i][j]), f5(grid[i][j])};
                vertical[i][j] = pr;
                horizontal[i][j] = pr;
                if(i != 0){
                    vertical[i][j].first += vertical[i - 1][j].first;
                    vertical[i][j].second += vertical[i - 1][j].second;
                }
                if(j != 0){
                    horizontal[i][j].first += horizontal[i][j - 1].first;
                    horizontal[i][j].second += horizontal[i][j - 1].second;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                // left, above
                int left_above =  min(horizontal[i][j].first + vertical[i][j].first - f2(grid[i][j]), horizontal[i][j].second + vertical[i][j].second - f5(grid[i][j]));
                int right_above = min(horizontal[i].back().first - horizontal[i][j].first + vertical[i][j].first, horizontal[i].back().second - horizontal[i][j].second + vertical[i][j].second);
                int left_below = min(horizontal[i][j].first + vertical.back()[j].first - vertical[i][j].first, horizontal[i][j].second + vertical.back()[j].second - vertical[i][j].second);
                int right_below = min(horizontal[i].back().first - horizontal[i][j].first + vertical.back()[j].first - vertical[i][j].first + f2(grid[i][j]),
                                      horizontal[i].back().second - horizontal[i][j].second + vertical.back()[j].second - vertical[i][j].second + f5(grid[i][j]) );
                ans = max({ans, left_above, left_below, right_above, right_below});
            }
        }


        return ans;

    }
};