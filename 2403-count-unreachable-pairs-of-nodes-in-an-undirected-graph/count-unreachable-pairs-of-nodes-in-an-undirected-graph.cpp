class Solution {
public:
    int dfs(int i, vector<vector<int>>&adj, vector<bool>&vis ){
        vis[i] = true;
        int count=1;
        for(auto j: adj[i]){
            if(!vis[j]){
                int ans = dfs(j,adj,vis);
                count += ans;
            }
        }
        return count;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(n,false);
        // vector<int>div;
        long long total = 0, sum = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int num = dfs(i,adj,vis);
                // div.push_back(num);
                total += (long long)num * sum;
                sum += num;
            }
        }


        // long long ans = 0;

        // for(int i=0;i<div.size()-1;i++){
        //     for(int j=i+1;j<div.size();j++){
        //         ans = ans + (long long)div[i]*(long long)div[j];
        //     }
        // }

        // return ans;
        
        // for (int size : div) {
        //     total += (long long)size * sum;
        //     sum += size;
        // }

        return total;
    }
};