void inOrder(TreeNode* root,vector<int> &res){
    if(root==NULL)
        return;
    
    inOrder(root->left,res);
    res.push_back(root->val);
    inOrder(root->right,res);
}
void preOrder(TreeNode* root,vector<int> &res){
    if(root==NULL)
        return;

    res.push_back(root->val);    
    inOrder(root->left,res);
    inOrder(root->right,res);
}

void postOrder(TreeNode* root,vector<int> &res){
    if(root==NULL)
        return;

    inOrder(root->left,res);
    inOrder(root->right,res);
    res.push_back(root->val);    
}

// level order recursive
void levelOrderHelper(TreeNode* root, vector<int> &res,int level){
    if(root==NULL)
        return;
    if(level==1)
        res.push_back(root->val);
    else{
        levelOrder(root->left,res,level-1);
        levelOrder(root->right,res,level-1);
    }
}

void levelOrder(TreeNode *root){
    vector<int> res;
    int height = calcHeight(root);
    for(int i=1;i<=height;i++)
        levelOrderHelper(root,res,i);
}