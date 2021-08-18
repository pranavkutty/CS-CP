// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

//recursive
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==p || root==q || root==NULL){
        return root;
    }
    
    TreeNode* leftRes = lowestCommonAncestor(root->left,p,q);
    TreeNode* rightRes = lowestCommonAncestor(root->right,p,q);
    
    if(leftRes && rightRes)
        return root;
    else if(leftRes)
        return leftRes;
    else
        return rightRes;
}