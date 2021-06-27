// counting inversions
// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#

void merge(long long nums[], long long &count,long long start,long long mid, long long end){
    long long i = start,j = mid+1,k=0;
    vector<long long> temp(end-start+1,0);
    
    while(i<=mid && j<=end){
        if(nums[i]<=nums[j]){
            temp[k++] = nums[i++];
        }
        else if(nums[i]>nums[j]){
            temp[k++] = nums[j++];
            count += (mid+1-i);
        }
    }
    
    while(i<=mid)
        temp[k++] = nums[i++];
    while(j<=end)
        temp[k++] = nums[j++];
    
    for(long long k=0;k<temp.size();k++){
        nums[k+start] = temp[k];
    }
    
}

void mergeSort(long long nums[],long long &count,long long start,long long end){
    if(start>=end){
        return ;
    }
    long long mid = start + (end-start)/2;
    
    mergeSort(nums,count,start,mid);
    mergeSort(nums,count,mid+1,end);
    
    merge(nums,count,start,mid,end);
    
}

long long int inversionCount(long long arr[], long long n)
{
    long long count = 0;
    
    mergeSort(arr,count,0,n-1);
    
    return count;
}