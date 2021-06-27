// possible words from phone digits
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

vector<string> map = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void letterCombinationsHelper(vector<string> &res,string &currStr,const string &digits,int index){
    if(index==digits.length()){
        res.push_back(currStr);
        return ;
    }
    if(index>digits.length())
        return ;
    
    int digit = digits[index] - '0';
    for(int i=0;i<map[digit].length();i++){
        currStr.push_back(map[digit][i]);
        letterCombinationsHelper(res,currStr,digits,index+1);
        currStr.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> res;
    if(digits.length()==0){
        return res;
    }
    string str = "";
    letterCombinationsHelper(res,str,digits,0);
    
    return res;
}