class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = 0;
        for(auto num: nums) maxi = max(maxi, num);
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==maxi){
                cnt++;
            }else{
                cnt = 0;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};