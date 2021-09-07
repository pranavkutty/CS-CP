// https://leetcode.com/problems/binary-tree-paths/

void pathHelper(TreeNode* root, string curr, vector<string> &res){
    if(root==NULL)
        return;
    curr += (to_string(root->val)+"->");
        
    if(!root->left && !root->right){
        if(!curr.empty()) curr.pop_back();
        if(!curr.empty()) curr.pop_back();
        res.push_back(curr);
        return;
    }
        
    pathHelper(root->left,curr,res);
    pathHelper(root->right,curr,res);
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    pathHelper(root,"",res);
    
    return res;
}