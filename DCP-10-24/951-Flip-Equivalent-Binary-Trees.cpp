class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        if(!root1 || !root2) return false;
        if(root1->val != root2->val) return false;

        int lV1 = -1, rV1 = -1, lV2 = -1, rV2 = -1;
        if(root1->left) lV1 = root1->left->val;
        if(root1->right) rV1 = root1->right->val;
        if(root2->left) lV2 = root2->left->val;
        if(root2->right) rV2 = root2->right->val;

        if(lV1 == lV2 && rV1 == rV2){
            return flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
        }else if(lV1==rV2 && rV1 == lV2){
            return flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
        }else{
            return false;
        }
        return true;
    }
};