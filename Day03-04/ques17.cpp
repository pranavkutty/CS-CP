// unique paths
// https://leetcode.com/problems/unique-paths/

int uniquePaths(int m, int n) {
    vector<vector<long long>> mat(m,vector<long long>(n,0));
    mat[0][0] = 1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i-1>=0) mat[i][j] += (mat[i-1][j]);
            if(j-1>=0) mat[i][j] += (mat[i][j-1]);
        }
    }
    return mat[m-1][n-1];
}