class Solution {
public:

    void dfs(int i,vector<vector<int>>& graph,vector<bool>visited,vector<int>temp,vector<vector<int>>&ans){
        visited[i] = true;
        temp.push_back(i);
        int n = graph.size();
        if(i==n-1){
            ans.push_back(temp);
        }
        for(auto j: graph[i]){
            if(!visited[j]){
                dfs(j,graph,visited,temp,ans);
            }
        }

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool>visited(n,false);
        vector<vector<int>>ans;
        vector<int>temp;
        dfs(0,graph,visited,temp,ans);
        return ans;
    }
};