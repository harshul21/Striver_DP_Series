//Youtube Link:- https://www.youtube.com/watch?v=xwomavsC86c&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=51
//Problem Link:- https://www.codingninjas.com/codestudio/problems/cost-to-cut-a-chocolate_3208460?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

//Bottom up
#include<bits/stdc++.h>
int dfs(int i,int j,vector<int> &cuts,vector<vector<int>> &dp){
    if(i>j)
        return 0;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mini=INT_MAX;
    for(int idx=i;idx<=j;idx++){
        int cost=cuts[j+1]-cuts[i-1]+dfs(i,idx-1,cuts,dp)+dfs(idx+1,j,cuts,dp);
        
        mini=min(mini,cost);
    }
    return dp[i][j]=mini;
}

int cost(int n, int c, vector<int> &cuts){
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
    return dfs(1,c,cuts,dp);
}