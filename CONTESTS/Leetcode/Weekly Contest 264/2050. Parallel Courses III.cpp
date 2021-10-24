class Solution {
public:
    vector<vector<int>> g;
    vector<int> score;  //earliest time of start
    vector<int> time;
    int dfs(int v){
        if(score[v]!=-1) return score[v];
        
        score[v] = 0;
        
        for(auto &c:g[v]){
            score[v] = max(score[v],dfs(c));
        }
        
        score[v] += time[v];
        return score[v];
    }
    
    int minimumTime(int n, vector<vector<int>>& rel, vector<int>& time) {
        this->time = time;
        //simple dfs and kind of dp
        score.assign(n,-1);
        g.assign(n,vector<int>());
        
        for(auto &c:rel)
            g[c[1]-1].emplace_back(c[0]-1);
        
        int ans = 0;
        for(int i=0;i<n;++i){
            dfs(i);
            ans = max(ans,score[i]);
        }
        
        return ans;
    }
};