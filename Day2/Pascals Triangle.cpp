#include <bits/stdc++.h>

void helper(vector<vector<long long int>>&ans ,vector<long long int> temp,int n){
  if(n==1)
  return;
  vector<long long int>v;
v.push_back(temp[0]);
  for(int i=1;i<temp.size();i++){
    v.push_back(temp[i-1]+temp[i]);
  }
v.push_back(temp[temp.size()-1]);
ans.push_back(v);
helper(ans,v,n-1);

}

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
    vector<vector<long long int>>ans;
    vector<long long int> temp;
    ans.push_back({1});
    temp.push_back(1);
    helper(ans,temp,n);
    return ans;
}
