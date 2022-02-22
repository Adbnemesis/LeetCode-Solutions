class Solution {
    
public:
    
    string help(TreeNode* root, unordered_map<string, int>& um,vector<TreeNode*>& ans){
        if(root == NULL){
            return " ";
        };
        string s = to_string(root->val) + " "+ help(root->left,um,ans)+ " "+ help(root->right,um,ans);
        if(um[s]++ == 1){
            ans.push_back(root);
        }
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> um;
        
        vector<TreeNode*> ans;
        help(root,um,ans);
        return ans;
    }
};
