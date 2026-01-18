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
    int findMinimum(TreeNode* root, TreeNode* curr, int maxi){
        if(!curr) return maxi;
        maxi = max(maxi, abs(root->val - curr->val));
        int leftCall = findMinimum(root,curr->left, maxi);
        int rightCall = findMinimum(root,curr->right, maxi);
        return max(leftCall, rightCall);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        int current = findMinimum(root, root, INT_MIN);
        int leftMax = maxAncestorDiff(root->left);
        int rightMax = maxAncestorDiff(root->right);
        int maxi = max(current, leftMax);
        return max(maxi, rightMax);
    }
};