class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        long long ans = 0;
        int target = n-1;
        for(int i = n-1; i>=0; i--){
            if(s[i]=='0'){
                continue;
            }else{
                ans += target-i;
                target = target-1;
            }
        }
        return ans;
    }
};