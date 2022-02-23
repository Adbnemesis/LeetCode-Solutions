class Solution {
public:
    vector<TreeNode*> inorder;
    
    
    void iorder(TreeNode* root){
        if(root == NULL)return;
        iorder(root->left);
        inorder.push_back(root);
        iorder(root->right);
    }
    
    TreeNode* solve(int start,int end){
        if(start>end)return NULL;
        int mid = (start+end)/2;
        TreeNode* root = inorder[mid];
        root->left = solve(start,mid-1);
        root->right = solve(mid+1,end);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {     
        iorder(root);
        TreeNode* Root = solve(0,inorder.size()-1);
        return Root;
        
    }
};
