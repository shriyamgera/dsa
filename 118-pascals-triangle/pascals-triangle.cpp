class Solution {
public:
    vector<int> generateRow (int row){
        vector<int> ans;
        ans.push_back(1);
        long long res = 1;
        for(int i = 1; i < row;i++){
            res = res * (row-i);
            res = res / (i);
            ans.push_back(res);
        }
        return ans;
    }


    vector<vector<int>> generate(int rows) {
        vector<vector<int>> ans;
        for( int i = 1; i<= rows; i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};