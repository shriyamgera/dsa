class Solution {
public:

    void dfsRoot(int i, vector<vector<int>>&adj, vector<bool>&visited, vector<int>&distances, int & level,vector<int>&childCount ){
        visited[i] = true;
        level++;
        for(auto j: adj[i]){
            if(!visited[j]){
                childCount[i]++;
                distances[0]+=level;
                dfsRoot(j,adj,visited,distances,level,childCount);
                childCount[i] += childCount[j];
            }
        }
        level--;
    }

        void dfs(int i,int n,int parent, vector<vector<int>>&adj, vector<int>&distances,vector<int>&childCount ){
        
        for(auto j: adj[i]){
            if(j != parent){
                distances[j] = distances[i] - (childCount[j] + 1) + (n-1-childCount[j]);
                dfs(j,n,i,adj,distances,childCount);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(int i = 0; i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        
        vector<int>distances(n,0);
        vector<int>childCount(n,0);
        vector<bool>visited(n,false);
        int level = 0;
        dfsRoot(0,adj,visited,distances,level,childCount);
        dfs(0,n,-1,adj,distances,childCount);
        return distances;
    }
};