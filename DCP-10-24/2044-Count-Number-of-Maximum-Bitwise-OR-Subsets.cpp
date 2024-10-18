class Solution {
    int cnt(vector<int>& nums, int s, int target, int curr){
        if(s==nums.size()) return target==curr;

        // take
        int ans = cnt(nums, s+1, target, curr|nums[s]);
        // not take
        ans += cnt(nums, s+1, target, curr);
        return ans;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        for(auto num: nums) maxOR |= num;
        return cnt(nums, 0, maxOR, 0);
    }
};