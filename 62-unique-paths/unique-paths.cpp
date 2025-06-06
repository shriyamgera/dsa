class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> arr(m, vector<int>(n, 0));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    arr[i][j]=1;
                }else{
                    arr[i][j]=arr[i][j-1]+arr[i-1][j];
                }
            }
        }
        count = arr[m-1][n-1];
        return count;
    }
};
