// generate parenthesis
// https://leetcode.com/problems/generate-parentheses/

void generateParenthesisHelper(vector<string> &res, int n, string &currRes, int index, int open, int close){
    if(index>2*n || close>open || open>n || close>n){
        return;
    }
    if(open==n && close==n){
        res.push_back(currRes);
        return;
    }
    
    currRes.push_back('(');
    generateParenthesisHelper(res,n,currRes,index+1,open+1,close);
    currRes.pop_back();
    currRes.push_back(')');
    generateParenthesisHelper(res,n,currRes,index+1,open,close+1);
    currRes.pop_back();
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    string str = "";
    generateParenthesisHelper(res,n,str,0,0,0);
    
    return res;        
}