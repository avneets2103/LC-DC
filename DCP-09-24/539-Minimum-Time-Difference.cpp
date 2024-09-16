class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> mins;
        for(auto t: timePoints){
            int h = stoi(t.substr(0, 2)), m = stoi(t.substr(3, 2));
            int min = h*60+m;
            mins.push_back(min);
        }
        sort(mins.begin(), mins.end());
        int ans = 1439;
        for(int i = 0; i<mins.size()-1; i++){
            ans = min(ans, mins[i+1]-mins[i]);
        }
        int n = mins.size();
        ans = min(ans, 1440-mins[n-1]+mins[0]);
        return ans;
    }
};