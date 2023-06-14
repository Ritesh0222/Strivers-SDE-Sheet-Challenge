#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &inter)
{
    // Write your code here.
    sort(inter.begin(),inter.end());

    vector<vector<int>>ans;
    ans.push_back(inter[0]);
    int x=0;
    for(int i=1;i<inter.size();i++){
        if(ans[x][1]>=inter[i][0]){
            ans[x][1]=max(ans[x][1],inter[i][1]);
        }
        else{
            ans.push_back(inter[i]);
            x++;
        }
    }
    return ans;

}
