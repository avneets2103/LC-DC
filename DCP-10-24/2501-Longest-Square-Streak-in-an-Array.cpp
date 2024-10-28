class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int, int> mp;
        unordered_map<int, bool> t;
        sort(nums.begin(), nums.end());
        int maxi = 1;
        for(int i = nums.size()-1; i>=0; i--){
            if(mp.count(nums[i])){continue;}
            mp[nums[i]]++;
            long long n = (long long)nums[i]* (long long)nums[i];
            mp[nums[i]] += mp[n];
            maxi = max(maxi, mp[nums[i]]);
        }
        if(maxi==1) return -1;
        return maxi;
    }
};