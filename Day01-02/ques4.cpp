// Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/


int binarySearchF(vector<int> &vec,int target,int start,int end){
    int n = vec.size();
    if(start>=end){
        if(start<n && vec[start]==target)
            return start;
        else if(end>=0 && vec[end]==target)   
            return end;
        else
            return -1;
    }

    int mid = start + (end-start)/2;
    if(vec[mid]==target && (mid==0 || vec[mid-1]!=target))
        return mid;
    
    if(vec[mid]>=target)
        return binarySearchF(vec,target,start,mid-1);
    else
        return binarySearchF(vec,target,mid+1,end);
}

int binarySearchL(vector<int> &vec,int target,int start,int end){
    int n = vec.size();
    if(start>=end){
        if(start<n && vec[start]==target)
            return start;
        else if(end>=0 && vec[end]==target)   
            return end;
        else
            return -1;
    }
        

    int mid = start + (end-start)/2;
    if(vec[mid]==target && (mid==n-1 || vec[mid+1]!=target))
        return mid;
    
    if(vec[mid]>target)
        return binarySearchL(vec,target,start,mid-1);
    else
        return binarySearchL(vec,target,mid+1,end);
}


vector<int> searchRange(vector<int>& vec, int target) {
    int n = vec.size();
    if(n==0)
        return {-1,-1};
    int first = binarySearchF(vec, target,0,n-1);
    int last = binarySearchL(vec,target,0,n-1);
    
    return {first,last};
}
