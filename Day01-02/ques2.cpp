// find pivot element index
// https://leetcode.com/problems/find-peak-element/

int binarySearch(vector<int> &nums,int start,int end,int n){
    if(start>=end){
        return start;
    }
    int mid = start + (end-start)/2;
    
    if(mid>0 && nums[mid]<=nums[mid-1])
        return binarySearch(nums,start,mid-1,n);
    
    else if(mid<n-1 && nums[mid]<=nums[mid+1])
        return binarySearch(nums,mid+1,end,n);
    
    else
        return mid;
}

int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return 0;
    else if(n==2){
        if(nums[0]>nums[1])
            return 0;
        else
            return 1;
    }
    return binarySearch(nums,0,n-1,n);
}