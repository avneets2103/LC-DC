class Solution {
    void split(string s, unordered_map<string, int>& mp){
        string temp = "";
        for(int i = 0; i<s.size(); i++){
            if(s[i]==' '){
                mp[temp]++;
                temp = "";
            }
            else{
                temp += s[i];
            }
            if(i==s.size()-1){
                mp[temp]++;
                break;
            }
        }
    }
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        split(s1, mp);
        split(s2, mp);
        vector<string> ans;
        for(auto p: mp){
            if(p.second==1) ans.push_back(p.first);
        }
        return ans;
    }
};