/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
struct Node {
    Node* child[26];
    bool isEnd;
};

class Trie {
    Node* root;
public:
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
    
    bool search(string word) {
        Node* head = root;
        for(auto &ch: word){
            int key = ch-'a';
            head = head->child[key];
            if(!head)
                return false;    
        }
        return head->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* head = root;
        for(auto &ch: prefix){
            int key = ch-'a';
            head = head->child[key];
            if(!head)
                return false;    
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

