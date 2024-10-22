#define ll long long
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0});
        ll currLvl = -1;
        ll currSum = 0;
        while(!q.empty()){
            pair<TreeNode*, ll> curr = q.front();
            q.pop();
            if(currLvl != curr.second && currLvl != -1){
                if(pq.size()<k) pq.push(currSum);
                else if(pq.top() < currSum){
                    pq.pop();
                    pq.push(currSum);
                }
                currSum = 0;
            }
            currLvl = curr.second;
            currSum += curr.first->val;
            if(curr.first->left){
                q.push({curr.first->left, curr.second+1});
            }
            if(curr.first->right){
                q.push({curr.first->right, curr.second+1});
            }
        }
        if(pq.size()<k) pq.push(currSum);
        else if(pq.top() < currSum){
            pq.pop();
            pq.push(currSum);
        }
        if(pq.size()<k) return -1;
        return pq.top();
    }
};