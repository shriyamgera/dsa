class Solution {
public:

void dfs(int i, vector<vector<int>>& adj,vector<bool>&visited, int &destination,bool &ans ){ 
    if(ans){
        return;
    }
    visited[i] = true;
    if(i==destination) ans = true;

    for(auto j: adj[i]){
        if(!visited[j]){
            dfs(j,adj,visited, destination, ans);
        }
    }
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        if(edges.size()==0 || edges.size()==1) return true;

        vector<vector<int>>adj(n);
        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n,false);
        bool ans = false;

        dfs(source,adj,visited, destination, ans);
        return ans;
    }
};