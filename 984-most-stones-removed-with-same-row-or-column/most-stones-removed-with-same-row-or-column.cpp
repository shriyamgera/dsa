class Solution {
public:
    void dfs(int i, vector<vector<int>>& stones, vector<bool>&visited, int&groups ){
        visited[i] = true;
        int n = stones.size();
        for(int j = 0; j<n; j++){
            int x = stones[j][0];
            int y = stones[j][1];

            if(!visited[j] && (stones[i][0] == x || stones[i][1] == y)){
                dfs(j,stones,visited,groups);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool>visited(n,false);
        int groups = 0; 

        for(int i = 0; i<n; i++){
            if(!visited[i]){
                dfs(i,stones,visited,groups);
                groups++;
            }
        }
        return n - groups;
    }
};