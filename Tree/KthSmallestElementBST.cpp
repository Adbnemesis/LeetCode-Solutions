class Solution {
public:
    priority_queue<int> pq;
    
    void solve(TreeNode*root,int k){
        if(root == NULL)return;
        if(pq.size()<=k)pq.push(root->val);
        if(pq.size()>k)pq.pop();
        solve(root->left,k);
        solve(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        solve(root,k);
        return pq.top();
    }
};
