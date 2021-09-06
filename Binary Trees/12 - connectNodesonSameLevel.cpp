// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

Node* connect(Node* root) {
    if(root==NULL)
        return NULL;
    
    queue<Node*> q;
    
    q.push(root);
    q.push(NULL);
    
    while(q.size()>1){
        Node* curr = q.front();
        q.pop();
        
        if(curr==NULL){
            q.push(NULL);
            continue;
        }
        
        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
        
        curr->next = q.front();
    }
    
    return root;
}