class Solution {
public:
    void dfs(int m, int n, int i, int j, vector<vector<bool>>& v, vector<vector<char>>& grid ){
        if(i<0 || j<0 || i>m || j>n || v[i][j] == true || grid[i][j] == '0'){
            return;
        }
        v[i][j] = true;
        dfs(m,n,i-1,j,v,grid);
        dfs(m,n,i+1,j,v,grid);
        dfs(m,n,i,j-1,v,grid);
        dfs(m,n,i,j+1,v,grid);
    }
    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size()-1;
        int n = grid[0].size()-1;
        vector<vector<bool>>v(m+1, vector<bool>(n+1,false));

        int islands = 0;

        for(int i = 0; i<=m; i++){
            for(int j = 0;j<=n; j++){
                if(!v[i][j] && grid[i][j] != '0'){
                    dfs(m,n,i,j,v,grid);
                    islands++;
                }
            }
        }

        return islands;
    }
};