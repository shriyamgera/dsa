class Solution {
public:

void dfs(int i, vector<vector<vector<int>>>&adj, vector<int>&visited, int&mini ){
    visited[i] = true;

    for(auto j: adj[i]){
        mini = min(j[1],mini);
        if(!visited[j[0]]){
            dfs(j[0],adj,visited,mini);
        }
    }
}
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<vector<int>>>adj(n+1);

        for(int i = 0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<int>visited(n+1);
        int mini = INT_MAX;
        dfs(1,adj,visited,mini);
        return mini;
    }
};