#include <bits/stdc++.h> 

void rev(vector<int>&per,int i){
    int j=per.size()-1;
    while(i<=j){
        swap(per[i++],per[j--]);
    }
}

vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    //find the index which break descending orer
    int i=n-2;
    while(i>=0&&permutation[i+1]<=permutation[i])
    i--;
    if(i>=0){
        //swapping with smallest greatest element in the suffix
        int j=n-1;
        while(permutation[j]<permutation[i])
        j--;
        
        swap(permutation[i],permutation[j]);

    }
    rev(permutation,i+1);
    return permutation;
}