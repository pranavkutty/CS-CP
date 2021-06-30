// restore ip address
// https://leetcode.com/problems/restore-ip-addresses/

bool isSafe(string &s, int index,int digit,int len){        
    int n = s.length();
    if(index+len>n || (s[index]=='0' && len!=1))
        return false;
    
    int digitsLeft = n-index-len;
    int minDigitsNeeded = 4-digit-1;
    int maxDigitsNeeded = (4-digit-1)*3;
    int ipNumber = stoi(s.substr(index,len));
    
    if(digitsLeft<minDigitsNeeded || digitsLeft>maxDigitsNeeded || ipNumber > 255){
        return false;
    }
    
    return true;
}

void restoreIpHelper(vector<string> &res, string &currRes, string &s,int index, int digit){
    int n = s.length();
    if(digit==4 && index>=n){
        res.push_back(currRes);
        return;
    }
    
    if(index>=n || digit>=4){
        return ;
    }
    
    for(int len=1;len<=3;len++){
        if(isSafe(s,index,digit,len)){
            string newString = s.substr(index,len);
            int prevLength = currRes.length();
            currRes.append(newString);
            if(digit<3){
                currRes.push_back('.');
                restoreIpHelper(res,currRes,s,index+len,digit+1);
                currRes.erase(currRes.begin()+prevLength,currRes.end());
            }
            else{
                restoreIpHelper(res,currRes,s,index+len,digit+1);
                currRes.erase(currRes.begin()+prevLength,currRes.end());
            }
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    string currRes="";
    
    restoreIpHelper(res,currRes,s,0,0);

    return res;
}