// palindrome partitioning
// https://leetcode.com/problems/palindrome-partitioning/

bool isPalin(string s){
    int low = 0,high = s.length()-1;
    while(low<high){
        if(s[low]!=s[high])
            return false;
        low++;
        high--;
    }
    return true;
}

void partitionHelper(vector<vector<string>> &res, vector<string> &currRes, string &s, int index){
    if(index>=s.length()){
        res.push_back(currRes);
        return;
    }
    
    for(int len=1;len<=(s.length()-index);len++){
        if(isPalin(s.substr(index,len))){
            currRes.push_back(s.substr(index,len));
            partitionHelper(res,currRes,s,index+len);
            currRes.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> currRes;
    partitionHelper(res,currRes,s,0);
    
    return res;
}