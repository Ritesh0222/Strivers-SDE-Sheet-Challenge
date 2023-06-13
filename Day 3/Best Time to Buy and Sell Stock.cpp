#include <bits/stdc++.h> 
int maximumProfit(vector<int> &arr){
    // Write your code here.
    int mini=INT_MAX,ans=0;
    for(int i=0;i<arr.size();i++){
        ans=max(arr[i]-mini,ans);
        mini=min(mini,arr[i]);
    }
    
    return ans;
}