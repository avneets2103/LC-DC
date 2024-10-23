class Solution {
    void levelOrder(vector<int>& levelSum, TreeNode* root){
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int currLvl = -1;
        int currSum = 0;
        while(!q.empty()){
            TreeNode* curr = q.front().first;
            int lvl = q.front().second;
            q.pop();
            if(lvl!=currLvl && currLvl!=-1){
                levelSum.push_back(currSum);
                currSum = 0;
            }
            currLvl = lvl;
            currSum += curr->val;
            if(curr->left){
                q.push({curr->left, lvl+1});
            }
            if(curr->right){
                q.push({curr->right, lvl+1});
            }
        }
        levelSum.push_back(currSum);
    }
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> levelSum;
        levelOrder(levelSum, root);
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            TreeNode* curr = q.front().first;
            int lvl = q.front().second;
            q.pop();
            if(lvl==0){
                curr->val=0;
            }
            if(levelSum.size() > lvl+1){
                int newVal = levelSum[lvl+1];
                if(curr->right) newVal -= curr->right->val;
                if(curr->left) newVal -= curr->left->val;
                if(curr->right) curr->right->val = newVal;
                if(curr->left) curr->left->val = newVal;
            }
            if(curr->right) q.push({curr->right, lvl+1});
            if(curr->left) q.push({curr->left, lvl+1});
        }
        return root;
    }
};