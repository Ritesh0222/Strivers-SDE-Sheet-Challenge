//brute force
#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	sort(arr.begin(), arr.end());

    for(int i=0; i<arr.size()-1; i++){

        if(arr[i]==arr[i+1])

        return arr[i];

    }

    return -1;
}
/*
Two type of Solution
I.Modify array
sort/use set/use negative Marking As i did
II.without Modify Array
use Binary Search on Property in case duplicate is present
"For the given number, the count of numbers less than or equal to it, exceeds 
the number itself"
so we find the first smallest number which satisfy above statement
->we can do that either by cheking linerly from 1 to n
-> or apply binary search if condition satisfy move left / decrement the number to check 
otherwise increment.
T.C->O(NlogN) S.C->O(1)
Two more Methods setbits and Floyd's Tortoise and Hare(To be solved*)
*/


//MYcode
// T.C->O(N) S.C->O(1)
#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
    int ans=0;
    for(int i=0;i<n;i++){
        if(arr[abs(arr[i])-1]<0)
          {  ans=abs(arr[i]);
          break;}
        arr[abs(arr[i])-1]*=-1;
//         cout<<arr[abs(arr[i])-1]<<endl;
    }
    return ans;  
}
//better solution

// think of it as linklist with cycle problem
#include<bits/stdc++.h>

using namespace std;
int findDuplicate(vector < int > & nums) {
  int slow = nums[0];
  int fast = nums[0];
  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (slow != fast);
  fast = nums[0];
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }
  return slow;
}
TC:O(n) SC:O(n)
//3rd
// M1 
using Binary Search 
if cnt is strictly greater than mid it means the repeating number __cpp_binary_lies 
from start to mid other wise it slies from mid+1 to end.


int findDuplicate_bs(int nums) {
        int len = nums.length;
        int low = 1;
        int high = len - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int cnt = 0;
            for (int i = 0; i < len; i++) {
                if (nums[i] <= mid) {
                    cnt++;
                }
            }

            if (cnt <= mid) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }

Time Complexity: O(nlogn)
Space Complexity: O(1)

