/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int findSum(TreeNode* root, int &maxSum){
        if(!root)
            return 0;
        int l = findSum(root->left, maxSum);
        int r = findSum(root->right, maxSum);
        int maxTopDownPath = max(root->val, root->val + max(l, r));
        int maxAcrossPath = root->val + l + r;
        maxSum = max(maxSum, max(maxTopDownPath, maxAcrossPath));
        return maxTopDownPath;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        findSum(root, maxSum);
        return maxSum;
    }
};
// @lc code=end

