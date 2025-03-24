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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++)mp[inorder[i]] = i;
        int n = postorder.size();
        return helper(postorder,inorder,0,n-1,0,n-1,mp);
    }
    TreeNode* helper(vector<int>&pos,vector<int>&in, int poss, int pose, int ins, int ine, unordered_map<int,int>&mp){
        if(poss > pose || ins > ine)return nullptr;
        TreeNode* root = new TreeNode(pos[pose]);
        int front = mp[pos[pose]] - ins;
        root->left = helper(pos, in, poss, poss+front-1, ins, mp[pos[pose]]-1, mp);
        root->right = helper(pos, in, poss+front, pose-1, mp[pos[pose]]+1, ine, mp);
        return root;
    }
};
