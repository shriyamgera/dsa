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
int xLevel = -1;
int yLevel = -1;
int xParent = -1;
int yParent = -1;

    bool dfs(TreeNode* parent, TreeNode* root, int level, int x, int y){
        if(!root) return false;
        if(root->val == x){
            xLevel = level;
            xParent = parent==NULL? NULL: parent->val;
        }
        if(root->val == y){
            yLevel = level;
            yParent = parent==NULL? NULL:  parent->val;
        }
        if(xLevel != -1 && yLevel != -1){
            if((xLevel==yLevel) && (xParent!=yParent)) return true;
            return false;
        }
        return dfs(root,root->left,level + 1,x,y) || dfs(root,root->right,level + 1,x,y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        return dfs(NULL,root,0,x,y);
    }
};