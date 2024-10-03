class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0;
        for(auto n: nums) sum = (sum+n)%p;
        unordered_map<int, int> mp;
        int modsum = 0;
        int ans = INT32_MAX;
        mp[0] = -1;
        for(int i = 0; i<nums.size(); i++){
            modsum = (modsum+nums[i])%p;
            mp[modsum] = i;
            int check;
            if(sum > modsum){
                check = p-(sum-modsum);
            }else{
                check = modsum-sum;
            }
            if(mp.count(check)){
                ans = min(ans, i-mp[check]);
            }
        }
        if(ans==nums.size()) ans = -1;
        return ans==INT32_MAX?-1:ans;
    }
};