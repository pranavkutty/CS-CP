vector<vector<int>> levelOrder(TreeNode* root) {
    if(root==NULL)
        return {};
    vector<vector<int>> res;
    vector<int> row;
    
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    
    while(q.size()>1){
        TreeNode* curr = q.front();
        q.pop();
        if(curr==NULL){
            res.push_back(row);
            row.clear();
            q.push(NULL);
            continue;
        }
        row.push_back(curr->val);
        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
    }
    
    if(row.size()>0)
        res.push_back(row);
    
    return res;        
}