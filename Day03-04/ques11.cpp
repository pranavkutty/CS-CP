// combination of numbers
// https://leetcode.com/problems/combinations/

void combineHelper(vector<vector<int>> &res, vector<int> &currRes, const int &k,const int &n,int &index){
    if(currRes.size()==k){
        res.push_back(currRes);
        return;
    }
    if(index>n){
        return;
    }
    
    //include curr element
    currRes.push_back(index);
    index++;
    combineHelper(res,currRes,k,n,index);
    currRes.pop_back();
    
    combineHelper(res,currRes,k,n,index);
    index--;
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> currRes;
    int index = 1;
    
    combineHelper(res,currRes,k,n,index);
    
    return res;
}