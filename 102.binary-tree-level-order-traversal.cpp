#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        if(!root)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            q.push(nullptr);
            vector<int> level;
            while(q.front() != nullptr){
                TreeNode* value = q.front();
                q.pop();
                level.push_back(value->val);
                if(value->left) q.push(value->left);
                if(value->right) q.push(value->right);
            }
            levels.push_back(level); 
            q.pop();
        }
        return levels;
    }
};
// @lc code=end

