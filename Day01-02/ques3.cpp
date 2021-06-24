// Search a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix/

int binarySearch1(vector<vector<int>> &mat,int target,int start,int end){
    int m = mat.size(),n = mat[0].size();

    if(start>=end || abs(start-end)==1){
        if(mat[start][0]<=target && mat[end][0]>target)
            return start;
        else if(mat[end][0]<=target)
            return end;
        else 
            return end;
    }
    
    int mid = start + (end-start)/2;
    if(mat[mid][0]>target)
        return binarySearch1(mat,target,start,mid-1);
    else if(mat[mid][0]<target)
        return binarySearch1(mat,target,mid,end);
    else
        return mid;
}

bool binarySearch(vector<vector<int>> &mat,int target,int start,int end,int row){
    int m = mat.size(),n = mat[0].size();
    if(start>end)
        return false;
    
    int mid = start + (end-start)/2;
    if(mat[row][mid]>target)
        return binarySearch(mat,target,start,mid-1,row);
    else if(mat[row][mid]<target)
        return binarySearch(mat,target,mid+1,end,row);
    else 
        return true;
}

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int row = binarySearch1(mat,target,0,mat.size()-1);
    return binarySearch(mat,target,0,mat[0].size()-1,row);
}