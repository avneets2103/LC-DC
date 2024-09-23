class Solution {
public:
    int solve(int s, int e, string& S, unordered_map<string, bool>& mp, vector<int>& dp){
        if(s>e){return 0;}
        if(dp[s]!=-1){return dp[s];}
        int mini = INT32_MAX;
        for(int j = s; j<=e; j++){
            int x = solve(j+1, e, S, mp, dp);
            if(mp.count(S.substr(s, j-s+1))==1){
                mini = min(mini, x);
            }
            mini = min(mini, j-s+1 + x);
        }
        return dp[s] = mini;
    }
    int minExtraChar(string s, vector<string>& dictionary){
        vector<int> dp(s.size(), -1);
        unordered_map<string, bool> mp;
        for(int i = 0; i<dictionary.size(); i++){
            mp[dictionary[i]] = true;
        }
        return solve(0, s.size()-1, s, mp, dp);
    }
};