#include <bits/stdc++.h>
//getting error in case duplicate
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   vector<vector<int>> ans;
   sort(arr.begin(),arr.end());
   int i=0,j=arr.size()-1;
   while(i<=j){
      if(arr[i]+arr[j]>s)
      j--;
      else if(arr[i]+arr[j]<s)
      i++;
      else{
         ans.push_back({arr[i],arr[j]});
         j--;
      }
   }
   return ans;
}
//Correct answer
#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
    vector<vector<int>> result;

   for(int i=0; i<arr.size(); i++){

      for(int j=i+1; j<arr.size(); j++){

         if(s-arr[i]==arr[j]){

            result.push_back({min(arr[i], arr[j]), max(arr[i], arr[j])});

         }

      }

   }

   sort(result.begin(), result.end());

   return result;
}