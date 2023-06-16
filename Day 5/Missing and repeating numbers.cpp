
#include <bits/stdc++.h> 
//Traverse the array. While traversing, use the absolute value of every element 
//as an index and make the value at this index as negative to mark it visited. 
//If something is already marked negative then this is the repeating element. 
//To find missing, traverse the array again and look for a positive value.
// T.C->O(N) 
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	int i;
    int a,b;
  
    for (i = 0; i < n; i++) {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
            b=abs(arr[i]);
    }
  
    for (i = 0; i < n; i++) {
        if (arr[i] > 0)
            a=i + 1;
    }
    return {a,b};
}
//Xor--->
In the result xor1, all elements would nullify each other except 
//x and y. All the bits that are set in xor1 will be set in either x or y.
// So if we take any set bit (We have chosen the rightmost set bit in code) of xor1 
//and divide the elements of the array in two sets – one set of elements with the same
// bit set and another set with the same bit not set. By doing so, we will
// get x in one set and y in another set. Now if we do XOR of all the elements in the 
//first set, we will get x, and by doing the same in the other set we will get y. 



void getTwoElements(int arr[], int n, int* x, int* y)
{
    /* Will hold xor of all elements and numbers
       from 1 to n */
    int xor1;
 
    /* Will have only single set bit of xor1 */
    int set_bit_no;
 
    int i;
    *x = 0;
    *y = 0;
 
    xor1 = arr[0];
 
    /* Get the xor of all array elements */
    for (i = 1; i < n; i++)
        xor1 = xor1 ^ arr[i];
 
    /* XOR the previous result with numbers
       from 1 to n*/
    for (i = 1; i <= n; i++)
        xor1 = xor1 ^ i;
 
    /* Get the rightmost set bit in set_bit_no */
    set_bit_no = xor1 & ~(xor1 - 1);
 
    /* Now divide elements in two sets by comparing
    rightmost set bit of xor1 with bit at same
    position in each element. Also, get XORs of two
    sets. The two XORs are the output elements. The
    following two for loops serve the purpose */
    for (i = 0; i < n; i++) {
        if (arr[i] & set_bit_no)
            /* arr[i] belongs to first set */
            *x = *x ^ arr[i];
 
        else
            /* arr[i] belongs to second set*/
            *y = *y ^ arr[i];
    }
    for (i = 1; i <= n; i++) {
        if (i & set_bit_no)
            /* i belongs to first set */
            *x = *x ^ i;
 
        else
            /* i belongs to second set*/
            *y = *y ^ i;
    }
 
    /* *x and *y hold the desired output elements */
}