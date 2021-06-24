// Stock buy sell to maximise profit
// https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1#

vector<vector<int>> stockBuySell(vector<int> arr, int n){
    vector<vector<int>> res;
    int start = 0;
    
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            int profit = (arr[i-1]-arr[start]);
            if(profit>0)
                res.push_back({start,i-1});
            
            start = i;
            
        }
    }
    if(arr[n-1]-arr[start]>0){
        res.push_back({start,n-1});
    }
    
    return res;
}