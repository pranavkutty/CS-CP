// count all possible paths from top-left to bottom-right

long long int numberOfPaths(int m, int n){
    vector<vector<long long>> mat(m,vector<long long>(n,0));
    mat[0][0] = 1;
    long long mod = pow(10,9)+7;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i-1>=0) mat[i][j] += (mat[i-1][j]%mod);
            if(j-1>=0) mat[i][j] += (mat[i][j-1]%mod);
        }
    }
    return mat[m-1][n-1]%mod;
}