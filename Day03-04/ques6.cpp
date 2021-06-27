// generate permutations
// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1#

void findPermutationHelper(vector<string> &res,string &s,int index){
    if(index>=s.length()){
        res.push_back(s);
        return;
    }
    
    for(int i=index;i<s.length();i++){
        swap(s[index],s[i]);
        findPermutationHelper(res,s,index+1);
        swap(s[index],s[i]);
    }
}

vector<string>find_permutation(string s)
{
    vector<string> res;
    findPermutationHelper(res,s,0);
    sort(res.begin(),res.end());
    return res;
}