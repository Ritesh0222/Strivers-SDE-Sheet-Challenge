#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int i=0,k=0,j=n-1;
   while(k<=j){
      if(arr[k]==0){
         swap(arr[i],arr[k]);
         i++;k++;
         //(SWAP(low and mid index element) and low++,mid++)
      }
      else if(arr[k]==1)
      k++;
      else{
         swap(arr[k],arr[j]);
         j--;
         //(SWAP(mid and high index element) and high--; because last element may be 0,1 ;then check again 
      }
   }
}