class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_map<string, bool> mp;
        vector<string> ans;
        for(auto str: folder) mp[str]=true;
        for(auto str: folder){
            string tstr = "";
            bool match = false;
            for(int i = 0; i<str.size()-2; i++){
                tstr += str[i];
                if(str[i+1]=='/' && mp.count(tstr)){
                    match = true;
                    break;
                }
            }
            if(!match) ans.push_back(str);
        }
        return ans;
    }
};