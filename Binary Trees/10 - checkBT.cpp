bool isLeaf(Node* root){
    return (!root->left && !root->right);
}


// full BT (all nodes except leaf nodes should have 2 children)
bool isFullTree (struct Node* root)
{
    if(root==NULL)
        return false;
    
    if(isLeaf(root))
        return true;
    
    return isFullTree(root->left) && isFullTree(root->right);
    
}

// complete binary tree
bool validation(queue<TreeNode*> &q){
    while(!q.empty()){
        if(!isLeaf(q.front()))
            return false;
        q.pop();
    }
    return true;
}

bool isCompleteTree(TreeNode* root) {
    queue<TreeNode*> q;
    
    q.push(root);
    
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        
        if(curr->left)
            q.push(curr->left);
        else{
            if(curr->right)
                return false;
            else
                return validation(q);
        }
        
        if(curr->right)
            q.push(curr->right);
        else
            return validation(q);            
    }
    
    return true;
}