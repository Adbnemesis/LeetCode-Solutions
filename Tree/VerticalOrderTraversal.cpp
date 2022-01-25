class Solution {
public:
    map<int,map<int,multiset<int>>> mms;
    void solve(TreeNode* root, int col, int row){
        if(root == NULL)return;
        mms[col][row].insert(root->val);
        solve(root->left,col-1,row+1);
        solve(root->right,col+1,row+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       solve(root,0,0);
        vector<vector<int>> ans;
        for(auto a: mms){
            ans.push_back(vector<int>());
                for(auto b : a.second){
                    for(auto c : b.second){
                        ans.back().push_back(c);
                    }
                }
            }
        
        return ans;
    }
};
