// Check if two people starting from different points ever meet
// https://www.geeksforgeeks.org/check-if-two-people-starting-from-different-points-ever-meet/

#include<bits/stdc++.h>

using namespace std;

int main(){
    int x1 = 6, v1 = 6, x2 = 4, v2 = 8;
    if(v1>v2){
        swap(x1,x2);
        swap(v1,v2);
    }
    else if(v1==v2 && x1!=x2){
        cout<<"No";
        return 0;
    }

    while(x2<=x1){
        if(x2==x1){
            cout<<"Yes";
            return 0;
        }
        x2 += v2;
        x1 += v1;
    }

    cout<<"No";
    return 0;

}