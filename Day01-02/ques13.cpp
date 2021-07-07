// kth smallest element in row-column sorted matrix

pair<int,int> findRankAndElement(vector<vector<int>> &mat,int num, int n){
    int count = 0, prevElement = mat[0][0];
    for(int i=0;i<n;i++){
        if(mat[i][0]>num)
            return {prevElement,count};
        if(mat[i][n-1]<=num){
            prevElement = mat[i][n-1];
            count += n;
            continue;
        }
        
        for(int j=0;j<n;j++){
            if(mat[i][j]<=num){
                count++;
                prevElement = max(prevElement,mat[i][j]);
            }
            else 
                break;
        }
    }
    
    return {prevElement,count};
    
}

int kthSmallest(vector<vector<int>>& mat, int k) {
    int n = mat.size();
    int low = mat[0][0], high = mat[n-1][n-1];
    int mid = mat[0][0];
    pair<int,int> midElement = {mat[0][0],0};
    while(low<=high){
        mid = low + (high-low)/2;
        
        midElement = findRankAndElement(mat,mid,n);
        
        if(midElement.second == k)
            return midElement.first;
        else if(midElement.second > k)
            high = mid-1;
        else
            low = mid+1;
    }
    
    return low;
}