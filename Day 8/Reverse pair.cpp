#include <bits/stdc++.h> 

void merge(vector<int>&arr,int l,int mid,int r,int &ans){
		//calculate reverse condition
	int a = mid+1;
        for(int i=l; i<=mid; i++){
            while(a<=r && arr[i] > 2*arr[a]){
                a++;
            }
            ans += a-(mid+1);
        }
/*
pick up the 1st array And check for   all the possible values which satisfy the conditions in this secondary array element
then similarly
we calculate all the possible values for all the elements of the first array
And include it in the answer

*/

    //sort the current chosen length subarray part of main array    
	int t=r-l+1;
	vector<int> temp(t,0);
	int lt=l,rt=mid+1,k=0;
	while(lt<=mid&&rt<=r){
		if(arr[lt]<arr[rt]){
			temp[k++]=arr[lt++];
		}
		else{
			temp[k++]=arr[rt++];
		}
	}
	while(lt<=mid){
		temp[k++]=arr[lt++];
	}
	while(rt<=r){
		temp[k++]=arr[rt++];
	}
	//put back temp in main arr

	int m=0;
	for(int i=l;i<=r;i++){
		arr[i]=temp[m++];
	}

}

void mergesort(vector<int>& arr,int l,int r,int &ans)
{
	if(l<r){
		int mid=l+(r-l)/2;
		mergesort(arr,l,mid,ans);
		mergesort(arr,mid+1,r,ans);
		merge(arr,l,mid,r,ans);
	}
}
int reversePairs(vector<int> &arr, int n){
	// Write your code here.	
	int ans=0;
	mergesort(arr,0,n-1,ans);
	return ans;
}