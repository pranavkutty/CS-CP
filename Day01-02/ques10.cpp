// Trapping Rain Water
// https://leetcode.com/problems/trapping-rain-water/

int trap(vector<int>& height) {
    int n = height.size();
    if(n<=2) return 0;

    vector<int> rmax(n,0);
    rmax[n-1] = 0;
    for(int i=n-2;i>=0;i--)
        rmax[i] = max(rmax[i+1],height[i+1]);
    
    int lmax = 0,sum = 0;
    for(int i=1;i<n-1;i++){
        lmax = max(lmax,height[i-1]);
        if(min(lmax,rmax[i])>height[i])
            sum += (min(lmax,rmax[i])-height[i]);
    }
    
    return sum;
}