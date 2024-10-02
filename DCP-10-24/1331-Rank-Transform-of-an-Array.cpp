class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> s;
        for(auto a: arr) s.insert(a);
        unordered_map<int, int> rank;
        int i = 1;
        for(auto st: s) rank[st] = i++;
        vector<int> ans;
        for(auto a: arr){
            ans.push_back(rank[a]);
        }
        return ans;
    }
};