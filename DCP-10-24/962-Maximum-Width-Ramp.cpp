class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int, int>> nump;
        for(int i = 0; i<nums.size(); i++) nump.push_back({nums[i], i});
        sort(nump.begin(), nump.end());
        int ans = 0;
        int maxI = -1;
        for(int i = nump.size()-1; i>=0; i--){
            maxI = max(maxI, nump[i].second);
            ans = max(maxI - nump[i].second, ans);
        }
        return ans;
    }
};