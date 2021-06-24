// Sort 0 1 2
// https://leetcode.com/problems/sort-colors/

void sortColors(vector<int>& nums) {
    int n = nums.size();
    int i=-1,j=0,k=n-1;
    
    while(j<=k){
        if(nums[j]==0){
            i++;
            swap(nums[j],nums[i]);
            j++;
        }
        else if(nums[j]==2){
            swap(nums[j],nums[k]);
            k--;
        }
        else{
            j++;
        }
    }
}