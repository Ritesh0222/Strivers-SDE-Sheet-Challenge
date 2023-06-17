/*
Start checking from the top right corner and implement the binary search
 and there will be no error when we decrement J because of there will be 
 no case when J will have to be increased again
 Time complexity is log (M into N)
*/
bool searchMatrix(vector<vector<int>>& mat, int target) {
        int i=0,m=mat.size(),n=mat[0].size();
        int j=n-1;
        while(i<m&&j<n){
            if(mat[i][j]<target){
                i++;
            }
            else if(mat[i][j]>target){
                j--;
            }
            else
            return true;
        }

        return false;
}