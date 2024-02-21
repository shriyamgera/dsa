#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void helper(vector<vector<int>>& chess, vector<vector<string>>& ans, int row) {
        if (row == chess.size()) {
            vector<string> temp;
            for (auto& row : chess) {
                string str = "";
                for (int col : row) {
                    str += (col == 1 ? "Q" : ".");
                }
                temp.push_back(str);
            }
            ans.push_back(temp);
            return;
        }

        for (int col = 0; col < chess.size(); col++) {
            if (validPlace(chess, row, col)) {
                chess[row][col] = 1;
                helper(chess, ans, row + 1);
                chess[row][col] = 0;
            }
        }
    }

    bool validPlace(vector<vector<int>>& chess, int row, int col) {
        for (int i = row - 1; i >= 0; i--) {
            if (chess[i][col] == 1) {
                return false;
            }
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chess[i][j] == 1) {
                return false;
            }
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < chess.size(); i--, j++) {
            if (chess[i][j] == 1) {
                return false;
            }
        }

        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> chess(n, vector<int>(n, 0));
        vector<vector<string>> ans;
        helper(chess, ans, 0);
        return ans;
    }
};
