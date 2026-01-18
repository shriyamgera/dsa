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

    bool solve(TreeNode* root, int targetSum, int current){
        if(!root) return false;
        current += root->val;
        if((!root->left && !root->right) && current == targetSum){
            return true;
        }
        return solve(root->left, targetSum, current) || solve(root->right, targetSum, current);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, targetSum, 0);
    }
};