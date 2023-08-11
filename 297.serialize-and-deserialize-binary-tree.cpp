#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
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
class Codec {
public:
    void se(TreeNode* root, string &s){
        if(!root){
            s.push_back('N');
            return;
        }
        // s.push_back(':');
        s.append(to_string(root->val));
        s.push_back(';');
        se(root->left, s);
        se(root->right, s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       string s = "";
       se(root, s); 
       return s;
    }

    TreeNode* de(string &s, int &idx){
        if(s[idx] == 'N'){
            ++idx;
            return nullptr;
        }
        int end = s.find(';', idx);
        TreeNode* node = new TreeNode(stoi(s.substr(idx, end-idx)));
        idx = end+1;
        node->left = de(s, idx);
        node->right = de(s, idx);
        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       int id = 0;
       return de(data, id); 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

