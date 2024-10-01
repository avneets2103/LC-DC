class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> cnt;
        for(auto n: arr) {cnt[n%k]++; cout<<n<<": "<<n%k<<endl;}
        if(cnt[0]%2!=0) return false;
        for(int i = 1; i<=k/2; i++){
            int a = cnt[i]-cnt[k-i];
            cnt[i] = max(0, a);
            cnt[k-i] = max(0, -a);
            int b = cnt[-i]-cnt[-(k-i)];
            cnt[-i] = max(0, b);
            cnt[-(k-i)] = max(0, -b);
        }
        for(int i = 1; i<k; i++){
            if(cnt[i]!=cnt[-i])return false;
        }
        return true;
    }
};