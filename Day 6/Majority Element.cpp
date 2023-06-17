
// Moore's voting algo Left to do????????
// 2 step 
// 1st find candidate 2nd verify it
// Intution==========
// Let Majority is x .if it apperars on left prefix 
// then its count must be greater than N/2 .
// If not then it must  appear on last suffix to be the majority
// element
// e.g 7 7 5 7 5 1 | 5 7 | 5 5 7 7 | 5 5 5 5 

/* Code
int  count=0;
int candidate=0;
for(int num:nums){
    if(count==0)
    candidate=num;
    if(num==candidate) count+=1;
    else count--;
}
*/
//For a possible candidate count will never be 0
#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int cand=-1,x=0;
	int cnt=0;
	for(int i=0;i<n;i++){
		if(cnt==0){
			//selects new candidate
			cand=arr[i];
		}
		if(cand==arr[i])//if cur==prev element
		cnt++;
		else cnt--;
	}
	//possible candidate = cand;
	// cout<<cand;
	for(int i=0;i<n;i++){
		if(arr[i]==cand)
		x++;
	}
	return x>floor(n/2)?cand:-1;
}

