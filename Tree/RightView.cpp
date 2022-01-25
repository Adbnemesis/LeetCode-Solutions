class Solution {
public:
    void helper(TreeNode* root, vector<int> &ans, int lvl, int& mlvl){
        if(root == NULL)return;
        if(mlvl<lvl){
            ans.push_back(root->val);
            mlvl = lvl;
        }
        helper(root->right,ans,lvl+1,mlvl);
        helper(root->left,ans,lvl+1,mlvl);
    }
    vector<int> rightSideView(TreeNode* root) {
        int mlvl = 0;
        vector<int> ans;
        helper(root,ans,1,mlvl);
        return ans;
    }
};
