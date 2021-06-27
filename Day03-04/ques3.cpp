// decode string - backtracking approach
// https://leetcode.com/problems/decode-ways/

void numDecodingHelper(int &count,string &s,int index){
    if(index>=s.length()){
        count++;
        return;
    }        
    if(s[index]=='0'){
        return;
    }
    
    if(index<s.length()-1){
        int digit1 = s[index]-'0';
        int digit2 = s[index+1]-'0';
        if((digit1*10+digit2)<=26){
            numDecodingHelper(count,s,index+2);
        }
    }
    
    numDecodingHelper(count,s,index+1);
}

int numDecodings(string s) {
    int count = 0;
    numDecodingHelper(count,s,0);
    return count;
}