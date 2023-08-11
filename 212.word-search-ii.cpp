#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
struct Node {
    Node *child[26];
    bool isEnd;
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
        for(int i = 0; i < 26; ++i)
            root->child[i] = nullptr;
        root->isEnd = false;
    }
    
    void insert(string word) {
        Node* head = root;
        for(auto &ch: word){
            int key = ch - 'a';
            if(head->child[key] == nullptr){
                head->child[key] = new Node();
            }
            head = head->child[key];
        }
        head->isEnd = true;
    }
};
class Solution {
    unordered_set<string> ans;
    int n, m;
public:
    void bt(vector<vector<char>>& board, int r, int c, string &str, Node* node){
        if(r < 0 || r >= n || c < 0 || c >= m || board[r][c] == '#')
            return;
        char ch = board[r][c];
        int key = ch - 'a';
        if(!(node->child[key]))
            return;
        node = node->child[key];   
        str.push_back(ch);
        board[r][c] = '#';
        if(node->isEnd)
            ans.insert(str);
        vector<pair<int, int>> offset = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(auto &pair: offset){
            bt(board, r+pair.first, c+pair.second, str, node);
        }
        str.pop_back();
        board[r][c] = ch;
    } 
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *trie = new Trie();
        string s;
        for(auto &word: words)
            trie->insert(word);
        n = board.size(); m = board[0].size();
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                bt(board, i, j, s, trie->root);
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
};
// @lc code=end

