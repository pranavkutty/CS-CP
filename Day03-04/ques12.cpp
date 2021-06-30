// n-queens
// https://leetcode.com/problems/n-queens/

bool isSafe(vector<string> &currRes,int n,int row,int col){
    //check horizontal
    for(int j=0;j<col;j++){
        if(currRes[row][j]=='Q')
            return false;
    }
    
    // check upper diagonal
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(currRes[i][j]=='Q')
            return false;
    }
    
    // lower diagonal
    for(int i=row+1,j=col-1;i<n && j>=0;i++, j--){
        if(currRes[i][j]=='Q')
            return false;
    }
    
    return true;
}

void nQueensHelper(vector<vector<string>> &res,vector<string> &currRes, int n,int col){
    if(col>=n){
        res.push_back(currRes);
        return;
    }
    
    for(int i=0;i<n;i++){
        if(isSafe(currRes,n,i,col)){
            currRes[i][col] = 'Q';
            nQueensHelper(res,currRes,n,col+1);
            currRes[i][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    string str(n,'.');
    vector<string> currRes(n,str);
    vector<vector<string>> res;
    
    nQueensHelper(res,currRes,n,0);
    
    return res;
}