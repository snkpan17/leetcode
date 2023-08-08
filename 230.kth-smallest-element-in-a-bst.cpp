/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 */

// @lc code=start
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
    int findKth(TreeNode* root, int &k){
        if(!root)
            return -1;
        int l = findKth(root->left, k);
        if(l != -1)
            return l;
        --k;
        if(k == 0){
            return root->val;
        }
        return findKth(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
       return findKth(root, k);
    }
};
// @lc code=end

