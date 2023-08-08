/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool checkValid(TreeNode* node, long long min, long long max){
        if(!node)
            return true;
        return node->val >= min && node->val <= max 
                && checkValid(node->left, min, ((long long)node->val)-1)
                && checkValid(node->right, ((long long)node->val)+1, max);
    }
public:
    bool isValidBST(TreeNode* root) {
       return checkValid(root, INT_MIN, INT_MAX); 
    }
};
// @lc code=end

