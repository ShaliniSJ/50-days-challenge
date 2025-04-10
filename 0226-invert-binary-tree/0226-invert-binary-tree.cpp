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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return root;
        stack<TreeNode*>st;
        TreeNode* curr = root;
        while(!st.empty() || curr){
            if(!curr){
                curr = st.top();
                st.pop();
                curr = curr->right;
            }
            if(curr){
                st.push(curr);
                swap(curr->left,curr->right);
                curr = curr->left;
            }
        }
        return root;
    }
};