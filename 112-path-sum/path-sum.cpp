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
    bool dfs(TreeNode* root, int ts, int sum){
        if(!root)return false;
        if(!root->left && !root->right){
            if(ts == sum+root->val)return true;
            return false;
        }
        return dfs(root->left,ts,sum+root->val) || dfs(root->right,ts,sum+root->val);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return false;
        return dfs(root,targetSum,0);
    }
};