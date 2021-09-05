// https://leetcode.com/problems/invert-binary-tree/

TreeNode* invertTree(TreeNode* root) {
    if(root==NULL)
        return NULL;
    
    TreeNode* newNode = new TreeNode(root->val);
    
    newNode->left = invertTree(root->right);
    newNode->right = invertTree(root->left);
    
    return newNode;
}