// alternative sorting
// https://practice.geeksforgeeks.org/problems/alternative-sorting1311/1#

vector<int> alternateSort(int arr[], int n)
{
    sort(arr,arr+n);
    vector<int> res(n,0);
    int high = n-1;
    for(int i=0;i<n;i+=2){
        res[i] = arr[high];
        high--;
    }
    int low = 0;
    for(int i=1;i<n;i+=2){
        res[i] = arr[low];
        low++;
    }
    
    return res;
}