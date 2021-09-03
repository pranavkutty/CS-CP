//inorder
vector<int> inOrder(Node* root)
{
    stack<Node*> s;
    vector<int> res;
    s.push(root);
    Node* curr = root->left;
    while(!s.empty() || curr!=NULL){
        while(curr!=NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        res.push_back(curr->data);
        curr = curr->right;
        s.pop();
    }
    return res;
}

//preorder
vector<int> preOrder(Node* root)
{
    stack<Node*> s;
    vector<int> res;
    s.push(root);
    res.push_back(root->data);
    Node* curr = root->left;
    while(!s.empty() || curr!=NULL){
        while(curr!=NULL){
            s.push(curr);
            res.push_back(curr->data);
            curr = curr->left;
        }
        curr = s.top();
        curr = curr->right;
        s.pop();
    }
    return res;
}

// level order
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

