// Missing number
// https://leetcode.com/problems/missing-number/

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int sum = (n)*(n+1)/2;
    
    for(int i=0;i<nums.size();i++){
            sum -= nums[i];
    }
    
    return sum;
}