class Solution {
public:

    int dfs(int node, vector<int>& scores, vector<vector<int>>& tree, set<int>& st,int remaining){

        st.insert(node);
        int res = 0;
        for(auto child: tree[node]){
            if(st.find(child) == st.end() and remaining){
                st.insert(child);
                res = max(res, dfs(child, scores, tree, st, remaining - 1));
                st.erase(child);
            }
        }
    }

    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        set<int>st;
        int n = scores.size();
        vector<vector<int>>tree(n,0);
        for(auto &u: edges){
            tree[u[0]].push_back(u[1]);
            tree[u[1]].push_back(u[0]);
        }

        int ans = 0;
        for(int i = 0; i < n; ++ i){
            ans = max(ans, dfs(i, scores, tree, st, 3));
        }

        return ans;
    }
};