// Search an element in a sorted and rotated array
// https://leetcode.com/problems/search-in-rotated-sorted-array/

int binarySearch(vector<int> &nums,int target, int start, int end){
    if(start>end)
        return -1;
    
    int mid = start + (end-start)/2;
    
    if(nums[mid]==target)
        return mid;
    else if(nums[mid]<target)
        return binarySearch(nums,target,mid+1,end);
    else
        return binarySearch(nums,target,start,mid-1);
}

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n-1,pivot = 0;
    
    while(low<=high){
        int mid = low + (high-low)/2;
        
        if(nums[mid]==target){
            return mid;
        }
        else if(mid<n-1 && nums[mid]>nums[mid+1]){
            pivot = mid+1;
            break;
        }
        else if(mid>0 && nums[mid]<nums[mid-1]){
            pivot = mid;
            break;
        }
        if(nums[mid]>nums[low])
            low = mid+1;
        else
            high = mid-1;
    }

    int res = binarySearch(nums,target,0,pivot-1);
    if(res==-1)
        res = binarySearch(nums,target,pivot,n-1);
    return res;
    
}