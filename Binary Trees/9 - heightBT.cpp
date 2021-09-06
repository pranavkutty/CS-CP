// https://leetcode.com/problems/maximum-depth-of-binary-tree/

void calcDepth(TreeNode* root, int &Max, int curr){
    if(root==NULL)
        return;
    curr++;
    Max = max(Max,curr);
    
    calcDepth(root->left,Max,curr);
    calcDepth(root->right,Max,curr);
}

int maxDepth(TreeNode* root) {
    int Max = 0;
    calcDepth(root,Max,0);
    
    return Max;
}