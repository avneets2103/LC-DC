class TrieNode{
    public:
    char val;
    bool end;
    vector<TrieNode*> children;
    TrieNode(char val){
        this->val = val;
        end = false;
        children = vector<TrieNode*>(10, NULL);
    }
};

class Trie{
    TrieNode* root;
    void insertH(string str, int s, TrieNode* node){
        if(s==str.size()) return;

        if(node->children[str[s]-'0']==NULL){
            node->children[str[s]-'0'] = new TrieNode(str[s]);
        }
        if(s==str.size()-1) node->children[str[s]-'0']->end = true;
        insertH(str, s+1, node->children[str[s]-'0']);
    }
    public:
    Trie(){
        root = new TrieNode('\0');
    }
    void insert(int num){
        string s = to_string(num);
        insertH(s, 0, root);
    }
    int maxMatch(int num){
        string s = to_string(num);
        int cnt = 0;
        TrieNode* curr = root;
        for(int i = 0; i<s.size(); i++){
            if(!curr->children[s[i]-'0']){
                return cnt;
            }
            curr = curr->children[s[i]-'0'];
            cnt++;
        }
        return cnt;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie t;
        for(auto n: arr1) t.insert(n);
        int maxi = 0;
        for(auto n: arr2) maxi = max(maxi, t.maxMatch(n));
        return maxi;
    }
};