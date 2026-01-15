/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void solve(TreeNode* root, int targetSum, vector<vector<int>>&ans, int currentSum, vector<int>currArr){
    if(root == NULL) return;

    currArr.push_back(root->val);
    currentSum+=root->val;
    if(root->left == NULL && root->right == NULL){
        if(currentSum == targetSum){
            ans.push_back(currArr);
        }
        return;
    }
        
        solve(root->left, targetSum, ans, currentSum, currArr);
        solve(root->right, targetSum, ans, currentSum, currArr);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>currArr;
        solve(root, targetSum, ans, 0, currArr);
        return ans;
    }
};