// Maximum sum subarray
// https://leetcode.com/problems/maximum-subarray/

int maxSubArray(vector<int>& nums) {
    int sum = nums[0],Max = nums[0];
    
    for(int i=1;i<nums.size();i++){
        if((sum + nums[i])<nums[i])                
            sum = nums[i];
        else
            sum += nums[i];
        Max = max(Max,sum);
    }
    Max = max(sum,Max);
    
    return Max;
}