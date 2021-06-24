// majority element
// https://leetcode.com/problems/majority-element/

int majorityElement(vector<int>& nums) {
    int count = 1;
    int cand = nums[0];
    int n = nums.size();
    for(int i=1;i<n;i++){
        if(nums[i]==cand)
            count++;
        else{
            count--;
            if(count==0){
                count = 1;
                cand = nums[i];
            }
        }
    }
    count = 0;
    
    for(int i=0;i<n;i++){
        if(nums[i]==cand)
            count++;
    }
    if(count>n/2)
        return cand;
    else
        return -1;
}