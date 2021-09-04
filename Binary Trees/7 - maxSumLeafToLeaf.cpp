// https://practice.geeksforgeeks.org/problems/maximum-path-sum/1#

long long maxPathSumHelper(Node* root, long long &maxSum){
    if(root==NULL)
        return 0;
        
        
    else if(root->left==NULL && root->right==NULL)
        return root->data;
        
        
    else if(root->left==NULL){
        long long sum = maxPathSumHelper(root->right,maxSum);
        return sum + root->data;
    }    
    else if(root->right==NULL){
        long long sum = maxPathSumHelper(root->left,maxSum);
        return sum + root->data;
    }
    else{
        long long ls = maxPathSumHelper(root->left,maxSum);
        long long rs = maxPathSumHelper(root->right,maxSum);
        maxSum = max(maxSum, ls+rs+root->data);
        long long currSum = max(ls,rs) + root->data;
        return currSum;
    }
}

int maxPathSum(Node* root)
{
    long long maxSum = INT_MIN;
    
    long long sum = maxPathSumHelper(root,maxSum);
    
    if(root->left==NULL || root->right==NULL)
        return max(maxSum,sum);
    else
        return maxSum;
}