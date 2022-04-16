
class Solution {
public:


    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        set<int>st;
        int n = scores.size();
        vector<vector<int>>tree(n,vector<int>(0,0));
        for(auto &u: edges){
            tree[u[0]].push_back(u[1]);
            tree[u[1]].push_back(u[0]);
        }
        for(int i = 0; i < n; ++ i){
            sort(tree[i].begin(), tree[i].end(),[&](const int &a, const int &b){
                return scores[a] > scores[b];
            });
        }

        int ans = -1;
        vector<int>res2;
        for(auto &e: edges){
            set<pair<int,int>>st;
            vector<int>res;

            int sum = 0;
            for(auto f: e){
                st.insert({scores[f], f});
                for(int i = 0; i < min(3, (int)tree[f].size()); ++ i){
                    int node = tree[f][i];
                    st.insert({ scores[node], node});
                }
            }
            if(st.size() >= 4){
                for(auto f: e) st.erase({scores[f], f}), sum += scores[f], res.push_back(f);
                int other2 = 2;
                while(other2--){
                    auto pr = *st.rbegin();
                    sum += pr.first;
                    res.push_back(pr.second);
                    st.erase(pr);
                }
                if(ans < sum){
                    ans = sum;
                    res2 = res;
                }
                // ans= max(ans, sum);
            }
        }
        // for(int i = 0 ;i < res2.size(); ++ i) {
        //     cout << res2[i] << " ";
        // }
        // cout <<endl;
        return ans;
    }
};