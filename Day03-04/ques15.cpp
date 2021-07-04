// Largest Number after k swaps
// https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1#

void findMaximumHelper(string &str,const int &n,const int &k,int index,int swaps,string &Max){
    if(index>=n-1 || swaps>=k){
        Max = max(Max,str);
        return ;
    }
    
    stack<int> s;
    s.push(index);
    
    for(int i=index+1;i<n;i++){
        while(!s.empty() && str[i]>str[s.top()])
            s.pop();
        if(s.empty() || str[s.top()]==str[i])
            s.push(i);
    }
    
    while(!s.empty()){
        swap(str[index],str[s.top()]);
        if(s.top()==index) swaps--;
        findMaximumHelper(str,n,k,index+1,swaps+1,Max);
        swap(str[index],str[s.top()]);
        s.pop();
    }
}

string findMaximumNum(string str, int k)
{
    string Max = str;
    int n = str.length();
    findMaximumHelper(str,n,k,0,0,Max);
    
    return Max;
}