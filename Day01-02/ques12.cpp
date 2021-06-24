// print matrix in spiral order
// https://leetcode.com/problems/spiral-matrix/

vector<int> spiralOrder(vector<vector<int>>& mat) {
    int m = mat.size(),n = mat[0].size();
    
    int top = 0,bottom = mat.size()-1,left = 0,right = mat[0].size()-1;
    vector<int> res;
    while(top<=bottom && left<=right){
        
        //left to right
        for(int j=left;j<=right;j++)
            res.push_back(mat[top][j]);
        top++;
        
        for(int i=top;i<=bottom;i++)
            res.push_back(mat[i][right]);
        right--;
        
        if(top<=bottom){
            for(int j=right;j>=left;j--)
                res.push_back(mat[bottom][j]);
            bottom--;
        }
        
        if(left<=right){
            for(int i=bottom;i>=top;i--)
                res.push_back(mat[i][left]);
            left++;
        }
    }
    
    return res;
}