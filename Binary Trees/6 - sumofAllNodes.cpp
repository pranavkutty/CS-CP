// https://practice.geeksforgeeks.org/problems/sum-of-binary-tree/1#

long int sumBT(Node* root)
{
    if(root==NULL)
        return 0;
    long ls = sumBT(root->left);
    long rs = sumBT(root->right);

    return ls+rs+root->key;
}