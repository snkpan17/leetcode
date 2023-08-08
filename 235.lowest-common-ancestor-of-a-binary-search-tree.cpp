/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* lca = nullptr;
public:
    bool findLCA(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &lca) {
        if(!root)
            return false;
        bool fl = findLCA(root->left, p, q, lca);
        bool fr = findLCA(root->right, p, q, lca);
        if(lca)
            return true;
        if(fl && fr){
            lca = root;
        }else if((fl || fr) && (root == p || root == q)){
            lca = root;
        }
        //!fl and !fr
        return fl || fr || root == p || root == q;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findLCA(root, p, q, lca);
        return lca;
    }
};
// @lc code=end

