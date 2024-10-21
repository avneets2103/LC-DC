class Solution {
    unordered_map<string, bool> contain;
    int solve(string str, int s){
        if(s==str.size()) return 0;

        int ans = 0;
        string newStr = "";
        for(int i = s; i<str.size(); i++){
            newStr += str[i];
            if(contain.count(newStr)==0){
                contain[newStr] = true;
                ans = max(ans, 1 + solve(str, i+1));
                contain.erase(newStr);
            }
        }
        return ans;
    }
public:
    int maxUniqueSplit(string s) {
        return solve(s, 0);
    }
};