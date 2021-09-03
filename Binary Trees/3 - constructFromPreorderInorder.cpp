// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

unordered_map<int,int> m;        // element to index mapping

bool isSafe(int pLeft, int pRight,int iLeft, int iRight, int n){
    if(pLeft>=n || pRight>=n || iLeft>=n || iRight>=n || pLeft<0 || pRight<0 || iLeft<0 || iRight<0)
        return false;
    return true;
}

TreeNode* buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int pLeft, int pRight, int iLeft, int iRight){
    
    // if(!isSafe(pLeft,pRight,iLeft,iRight,preorder.size()))
    //     return NULL;
    
    if(pLeft == pRight){
        TreeNode* root = new TreeNode(preorder[pLeft]);
        return root;
    }
    else if(pLeft > pRight)
        return NULL;
    
    TreeNode* root = new TreeNode(preorder[pLeft]);
    
    int index = m[preorder[pLeft]];
    int pLeft1 = pLeft + 1;
    int pRight1 = pLeft + (index - iLeft);
    
    root->left = buildTreeHelper(preorder,inorder,pLeft1,pRight1,iLeft,index-1);
    
    pLeft1 = pRight1 + 1;
    pRight1 = pLeft1 + (iRight - index - 1);
    
    root->right = buildTreeHelper(preorder,inorder,pLeft1,pRight1,index+1,iRight);
    
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    
    int n = preorder.size();
    
    for(int i=0;i<n;i++)
        m[inorder[i]] = i;
    
    int pLeft = 0, pRight = n-1, iLeft = 0, iRight = n-1;
    
    return buildTreeHelper(preorder, inorder, pLeft, pRight, iLeft, iRight);
    
}