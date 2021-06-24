// Given a binary array A[] of size N. The task is to arrange the array in increasing order.
// https://practice.geeksforgeeks.org/problems/binary-array-sorting-1587115620/1

void binSort(int arr[], int n)
{
    int i=-1,j=0;
    
    while(j<n){
        if(arr[j]==0){
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
}
