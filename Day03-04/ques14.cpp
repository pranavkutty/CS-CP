// power-set
// https://leetcode.com/problems/subsets/

void subsetsHelper(vector<vector<int>> &res,vector<int> &currRes, vector<int> &nums, const int &n, int index){
    if(index>=n){
        res.push_back(currRes);
        return;
    }
    
    currRes.push_back(nums[index]);
    subsetsHelper(res,currRes,nums,n,index+1);
    currRes.pop_back();
    subsetsHelper(res,currRes,nums,n,index+1);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> currRes;
    int n = nums.size();
    
    subsetsHelper(res,currRes,nums,n,0);
    
    return res;
}