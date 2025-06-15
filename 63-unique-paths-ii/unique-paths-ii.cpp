// class Solution {
// public:
//     void findCount(vector<vector<int>>& arr, int m, int n, int i, int j,
//                    int& count) {
//                     if(arr[m][n]==1){
//             return;
//         }
//         if (i == m && j == n) {
//             count++;
//             return;
//         }
//         if (i > m || j > n) {
//             return;
//         }
//         if(arr[i][j]==1){
//             return;
//         }
//          else {
//             findCount(arr, m, n, i, j + 1, count);
//             findCount(arr, m, n, i + 1, j, count);
//         }
//     }

//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int count = 0;
//         int m = obstacleGrid.size() - 1;
//         int n = obstacleGrid[0].size() - 1;
//         findCount(obstacleGrid, m, n, 0, 0, count);
//         return count;
//     }
// };

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> obsMat(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0] == 0){
                obsMat[i][0] = 1;
            }else break;
        }
        for(int i=0;i<n;i++){
            if(obstacleGrid[0][i] == 0){
                obsMat[0][i] = 1;
            }else break;
        }
        for(int i = 1; i<m;i++){
            for(int j = 1;j<n;j++){
                if(obstacleGrid[i][j] == 1) obsMat[i][j] = 0;
                else obsMat[i][j] = obsMat[i-1][j] + obsMat[i][j-1];
            }
        }
        return obsMat[m-1][n-1];
    }
};