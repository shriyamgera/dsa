class Solution {
public:

    void dfs(int i,vector<vector<int>>& graph,vector<int>temp,vector<vector<int>>&ans){
        temp.push_back(i);
        int n = graph.size();
        if(i==n-1){
            ans.push_back(temp);
        }else{
            for(auto j: graph[i]){
            dfs(j,graph,temp,ans);
        }
        }

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>ans;
        vector<int>temp;
        dfs(0,graph,temp,ans);
        return ans;
    }
};