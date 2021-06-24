// Minimum Number of Platforms Required for a Railway/Bus Station
// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr,arr+n);
    sort(dep,dep+n);
    
    int count = 1,Max = 1,i=1,j=0;
    
    while(i<n){
        if(arr[i]<=dep[j]){
            count++;
            i++;
            Max = max(Max,count);
        }
        else{
            count--;
            j++;
        }
    }
    
    return Max;
}