// excel-sheet column title
// https://leetcode.com/problems/excel-sheet-column-title/

void convertToTitleHelper(int columnNumber, string &res){
    if(columnNumber==0){
        return;
    }
    if(columnNumber<=26){
        res.push_back(64+columnNumber);
        return;
    }
    
    columnNumber -= 1;
    
    int nextInt = columnNumber/26;
    int currRes = columnNumber%26;
    res.push_back('A'+currRes);
    
    convertToTitleHelper(nextInt,res);
}

string convertToTitle(int columnNumber) {
    string res="";
    
    convertToTitleHelper(columnNumber,res);
    
    reverse(res.begin(),res.end());
    
    return res;
}