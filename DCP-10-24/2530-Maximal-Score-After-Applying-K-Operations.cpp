class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<long long> pq;
        for(auto n: nums) pq.push(n);
        while(k--){
            long long tp = pq.top();
            pq.pop();
            ans += tp;
            long long rep = tp/3 + (tp%3>0);
            pq.push(rep);
        }
        return ans;
    }
};