#include <bits/stdc++.h>



//1 2 3 0 0 
//4 5
//=>>>>>>1 2 3 4 5


vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
	int i=m-1,j=n-1,k=m+n-1;

	while(i>=0&&j>=0){
		if(arr1[i]>=arr2[j]){
			arr1[k]=arr1[i];
			i--;
		}
		else{
			arr1[k]=arr2[j];
			j--;
		}
		k--;
	}	
	while(i>=0){
		arr1[k]=arr1[i];
		i--;
		k--;
	}
	while(j>=0){
		arr1[k]=arr2[j];
		j--;k--;
	}
	return arr1;
}