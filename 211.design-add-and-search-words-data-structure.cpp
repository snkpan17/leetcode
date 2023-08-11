/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start
struct Node {
    Node* child[26];
    bool isEnd;
};

class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root = new Node();
        for(int i = 0; i < 26; ++i)
            root->child[i] = nullptr;
        root->isEnd = false;
        // root = nullptr;
    }
    
    void addWord(string word) {
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
    bool find(Node* node, string &word, int idx){
        if(!node)
            return false;
        if(idx == word.length())
            return node->isEnd;
        int key = word[idx] - 'a';
        if(word[idx] != '.')
            return find(node->child[key], word, idx+1);
        for(int i = 0; i < 26; ++i){
            if(node->child[i] && find(node->child[i], word, idx+1))
                return true;
        }
        return false;
    }
    bool search(string word) {
       return find(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

