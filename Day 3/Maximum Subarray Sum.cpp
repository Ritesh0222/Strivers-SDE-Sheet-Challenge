#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    /*
       Kdanes algorithm
    */
    int maxi=0;
    int temp=0;
    for(int i=0;i<n;i++){
        temp+=arr[i];
        maxi=max(maxi,temp);
        if(temp<0)
        temp=0;
    }
    return maxi;
}