// equal subset sum
// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1#
bool canPartitionHelper(int nums[],int &sum,int index,int &currSum, const int &n){
    if(index>=n || currSum>sum)
        return false;
    
    if(currSum==sum){
        return true;
    }
    
    // include current element
    sum -= nums[index];
    currSum += nums[index];
    if(canPartitionHelper(nums,sum,index+1,currSum,n))
        return true;
    sum += nums[index];
    currSum -= nums[index];
    
    
    return canPartitionHelper(nums,sum,index+1,currSum,n);
}

bool canPartition(int nums[],int N) {
    int sum = 0,currSum = 0;
    
    for(int i=0;i<N;i++)
        sum += nums[i];
        
    if(sum%2!=0) return false;
    
    return canPartitionHelper(nums,sum,0,currSum,N);
    
}
int equalPartition(int N, int arr[])
{
    return canPartition(arr,N);
}