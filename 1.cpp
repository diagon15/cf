class Solution {
public:
    int n, m;
    bool isvalid(int i,int j){
        return (0 <= i and 0 <= j and i < n and j < m);
    }

    int minimumObstacles(vector<vector<int>>& grid) {


        n = grid.size();
        m = grid[0].size();

        priority_queue<vector<int>>pq;
        int visited[n][m];
        fill_n(&visited[0][0], n*m, 0);
        // unordered_map<pair<int,int>, int>visited;

        int ans = -1;

        pq.push({0, 0 , 0});
        visited[0][0] = 1;
        int nx[]={0 , 0, -1, 1};
        int ny[]={1, -1, 0, 0};
        while(not pq.empty()){
            const vector<int> tp = pq.top();
            pq.pop();

            int w =  -tp[0];
            int i_ = tp[1];
            int j_ = tp[2];
            // cout << w << "  " << i_ << " " << j_ << " " <<"\n";
            for(int i = 0; i < 4; ++ i){
                int newi = nx[i] + i_;
                int newj = ny[i] + j_;
                if((0 <= newi and 0 <= newj and newi < n and newj < m) and not visited[newi][newj]){
                    if(newi == n - 1 and newj == m - 1){
                        ans = w;
                        break;
                    }
                    else {
                        pq.push({-(w + grid[newi][newj]), newi, newj});
                        // visited[newi][newj] = 1;
                        visited[newi][newj] = 1;
                    }
                }
            }
            if(-1 != ans) break;
        }

        return ans;
    }
};