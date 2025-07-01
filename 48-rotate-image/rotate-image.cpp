class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // vector<vector<int>>mat(n,vector<int>(n,0));
        // for(int i = 0;i<n;i++){
        //     for(int j = 0;j<n;j++){
        //         mat[i][j] = matrix[n-j-1][i];
        //     }
        // }
        // matrix = mat;

        
        
        

        for(int i = 0;i<n/2;i++){
            for(int j = i;j<n-i-1;j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = temp;
            }
        }
        
    }
};