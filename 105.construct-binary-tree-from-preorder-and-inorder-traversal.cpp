#include<bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* tree(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir, map<int, int> &m) {
        if(pl > pr || il > ir)
            return nullptr;
        TreeNode* head = new TreeNode(preorder[pl]);    
        // auto itr = lower_bound(inorder.begin(), inorder.end(), head->val);
        // int idx = itr - inorder.begin();
        int idx = m[preorder[pl]];
        int nl = idx - il;
        int nr = ir - idx;
        head->left = tree(preorder, inorder, pl+1, pl+nl, idx-nl, idx-1, m);
        head->right = tree(preorder, inorder, pl+nl+1, pl+nl+nr, idx+1, idx+nr, m);
        return head;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       map<int, int> m;
       for(int i = 0; i < inorder.size(); ++i){
        m[inorder[i]] = i;
       }
       return tree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1, m);
    }
};
// @lc code=end
int main() {
    Solution s = Solution();
    s.buildTree({3, 9, 20, 15, 7}, {9, 3, })
}
