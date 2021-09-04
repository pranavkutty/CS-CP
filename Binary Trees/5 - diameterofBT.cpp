// https://leetcode.com/problems/diameter-of-binary-tree/

int maxHeight(TreeNode* root, int &diameter){
    if(root==NULL)
        return 0;
    
    int lh = maxHeight(root->left,diameter);
    int rh = maxHeight(root->right,diameter);
    
    diameter = max(diameter,lh+rh);
    
    return max(lh,rh) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    
    maxHeight(root,diameter);
    
    return diameter;
}