/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.

*/

struct TrieNode{
    
    TrieNode* a[26];
    bool isEnd;
    
    TrieNode(){
        for(int i = 0; i < 26; i++){
            a[i] = NULL;
        }
        isEnd = false;
    }
};
class Trie {
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* temp = root;
        
        for(int i = 0; i < word.length(); i++){
            
            int curr = word[i] - 'a';
            if(temp->a[curr] == NULL)
                temp-> a[curr] = new TrieNode();
            
            temp = temp-> a[curr];
        }
        
        temp->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* temp = root;
        
        for(int i = 0; i < word.size(); i++){
            
            int curr = word[i] - 'a';
            
            if(temp-> a[curr] == NULL)
                return false;
            temp = temp-> a[curr];
        }
        
        return temp->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        
        for(int i = 0; i < prefix.size(); i++){
            int curr = prefix[i] - 'a';
            
            if(temp-> a[curr] == NULL)
                return false;
            temp = temp-> a[curr];
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
