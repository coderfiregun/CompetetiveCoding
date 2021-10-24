class Solution {
public:
    int n;
    vector<long> score;
    vector<vector<int>> g;
    
    long dfs(int v){
        
        vector<long> childscores;
        long sumChildScores = 0;
        
        for(auto &c:g[v]){
            childscores.emplace_back(dfs(c));
            sumChildScores += childscores.back();
        }
        
        long extra = n-(1+sumChildScores);
        score[v] = max(1L,extra);
        for(auto &c:childscores){
            score[v] *= c;
        }
        return 1+sumChildScores;
    }
    
    int countHighestScoreNodes(vector<int>& par) {
        this->n = par.size();
        
        g.assign(n,vector<int>());
        score.resize(n);
        
        for(int i=1;i<par.size();++i){
            g[par[i]].emplace_back(i);
        }
        
        dfs(0);
        
        long mx = LLONG_MIN;
        for(auto &c:score) mx = max(mx,c);
        int cnt = 0;
        for(auto &c:score){
            // cout<<c<<endl;
            if(c==mx) ++cnt;
        }
        return cnt;
    }
};