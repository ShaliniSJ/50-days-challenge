class Node{
    public:
    Node* links[26];
    bool end = false;
};

class Trie {
public:
    Node* root = new Node();
    Trie() {}
    
    void insert(string word) {
        Node* temp = root;
        for(auto ch:word){
            if(temp->links[ch-'a'] == nullptr) temp->links[ch-'a'] = new Node();
            temp = temp->links[ch-'a'];
        }
        temp->end = true;
    }
    
    bool search(string word) {
        Node* temp = root;
        for(auto ch:word){
            if(temp->links[ch-'a'] == nullptr)return false;
            temp = temp->links[ch-'a'];
        }
        return temp->end == true;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(auto ch:prefix){
            if(temp->links[ch-'a'] == nullptr)return false;
            temp = temp->links[ch-'a'];
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