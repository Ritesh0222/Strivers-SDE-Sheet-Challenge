#include <bits/stdc++.h>
//The main goal is to get the exponent without overflowing the int capacity
int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	int res=1;
	x=x%m;
	while(n>0){
		//check if  n is odd
		if(n&1)
		res=(1LL*res*x)%m;
		n=n/2;
		x=(1LL*x*x)%m;
	}

	return res%m;
}
// T.C->O(log n)
// here use 1LL to avoid skiping/oveflow of digit
// wrong :res=(res*x)%m;
// Right:res=(1LL*res*x)%m;
// when n is odd we store it once in the result and we divide in by two and 
// when we divide n by two we double the value of X power that is exponent and 
// again in the next round when in is again odd we again multiply res with current x
// so that current x power get added to res;


// Another recursive approach is 
//recursive approach
  double pow(double x, int n)
    {
        if(n==0)
            return 1;
        
        double temp = pow(x,n/2);      //eases the process since we need not care about inc/dec
        
        if(n % 2 == 0)
            return temp * temp ;
        else
            return x * temp * temp ;
    }