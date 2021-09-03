
// right view
vector<int> rightSideView(TreeNode* root) {
    if(root==NULL)
        return {};
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    vector<int> res;
    
    while(q.size()>1){
        TreeNode* curr = q.front();
        q.pop();
        
        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
        
        if(q.front()==NULL){
            q.pop();
            q.push(NULL);
            res.push_back(curr->val);
        }
    }
    
    return res;
}

//left view
vector<int> leftView(Node *root)
{
    if(root==NULL)
        return {};
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    vector<int> res;
    
    while(q.size()>1){
        Node* curr = q.front();
        q.pop();
        
        if(curr->right)
            q.push(curr->right);
        if(curr->left)
            q.push(curr->left);
        
        if(q.front()==NULL){
            q.pop();
            q.push(NULL);
            res.push_back(curr->data);
        }
    }
    
    return res;
}

//bottom view
void preOrder(map<int,pair<int,int>> &m, Node* root, int col, int level){ 
    if(root==NULL)
        return;
    
    if(m.find(col)!=m.end()){
        if(m[col].first <= level)
            m[col] = {level,root->data};
    }
    else
        m[col] = {level,root->data};
        
    preOrder(m,root->left,col-1,level+1);
    preOrder(m,root->right,col+1,level+1);
}

vector <int> bottomView(Node *root) {
    map<int,pair<int,int>> m;
    vector<int> res;
    
    preOrder(m,root,0,0);
    
    for(auto itr = m.begin();itr!=m.end();itr++)
        res.push_back((itr->second).second);
    
    return res;
}

// top view
void preOrder(map<int,pair<int,int>> &m, Node* root, int col, int level){
        
    if(root==NULL)
        return;
    
    if(m.find(col)!=m.end()){
        if(m[col].first > level)
            m[col] = {level,root->data};
    }
    else
        m[col] = {level,root->data};
        
    preOrder(m,root->left,col-1,level+1);
    preOrder(m,root->right,col+1,level+1);
}

vector<int> topView(Node *root)
{
    map<int,pair<int,int>> m;
    vector<int> res;
    
    preOrder(m,root,0,0);
    
    for(auto itr = m.begin();itr!=m.end();itr++)
        res.push_back((itr->second).second);
    
    return res;
}