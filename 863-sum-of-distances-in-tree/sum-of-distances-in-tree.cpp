class Solution {
public:

    void dfsRoot(int i, vector<vector<int>>&adj, vector<bool>&visited, vector<int>&distances, int & level,vector<int>&parents,vector<int>&childCount ){
        visited[i] = true;
        level++;
        for(auto j: adj[i]){
            if(!visited[j]){
                parents[j] = i;
                childCount[i]++;
                distances[0]+=level;
                dfsRoot(j,adj,visited,distances,level,parents,childCount);
                childCount[i] += childCount[j];
            }
        }
        level--;
    }

        void dfs(int i,int n, vector<vector<int>>&adj, vector<int>&distances,vector<int>&parents,vector<int>&childCount ){
        
        for(auto j: adj[i]){
            if(j != parents[i]){
                distances[j] = distances[parents[j]] - (childCount[j] + 1) + (n-1-childCount[j]);
                dfs(j,n,adj,distances,parents,childCount);
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
        vector<int>parents(n,-1);
        vector<int>childCount(n,0);
        vector<bool>visited(n,false);
        int level = 0;
        dfsRoot(0,adj,visited,distances,level,parents,childCount);
        dfs(0,n,adj,distances,parents,childCount);
        return distances;
    }
};