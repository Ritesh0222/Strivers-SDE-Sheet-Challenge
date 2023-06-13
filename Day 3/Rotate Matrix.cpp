//rotate Matrix or spiral matrix question think of this common pattern as in this :
#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int left=0,right=m-1,top=0,bottom=n-1;
    while(left<right&top<bottom){
        int temp=mat[top][left];
        //fix the top row
        for(int col=left+1;col<=right;col++){
            int t=mat[top][col];
            mat[top][col]=temp;
            temp=t;
        }
        top++;//godown

        //fix last column
        for(int row=top;row<=bottom;row++){
            int t=mat[row][right];
            mat[row][right]=temp;
            temp=t;
        }
        right--;

        //fix last row
        for(int col=right;col>=left;col--){
            int t=mat[bottom][col];
            mat[bottom][col]=temp;
            temp=t;
        }
        bottom--;//goup

        //fix first column
        for(int row=bottom;row>=top;row--){
            int t=mat[row][left];
            mat[row][left]=temp;
            temp=t;
        }
        left++;

        mat[top-1][left-1]=temp;
    }

}