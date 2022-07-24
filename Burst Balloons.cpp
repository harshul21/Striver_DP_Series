//Youtube Link:- https://www.youtube.com/watch?v=Yz4LlDSlkns&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=52
//Problem Link:- https://www.codingninjas.com/codestudio/problems/mining-diamonds_4244494?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

//Recursive Approach
#include<bits/stdc++.h>
int dfs(int i,int j,vector<int> &a,vector<vector<int>> &dp){
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int maxi=INT_MIN;
    for(int idx=i;idx<=j;idx++){
        int cost=a[i-1]*a[idx]*a[j+1]+dfs(i,idx-1,a,dp)+dfs(idx+1,j,a,dp);
        maxi=max(maxi,cost);
    }
    return dp[i][j]=maxi;
}
int maxCoins(vector<int>& a)
{
    int n=a.size();
    a.push_back(1);
    a.insert(a.begin(),1);
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return dfs(1,n,a,dp);
}

//Tabulation
#include<bits/stdc++.h>
int maxCoins(vector<int>& a)
{
    int n=a.size();
    a.push_back(1);
    a.insert(a.begin(),1);
    vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
            if(i>j){
                continue;
            }
            int maxi=INT_MIN;
            for(int idx=i;idx<=j;idx++){
                int cost=a[i-1]*a[idx]*a[j+1]+dp[i][idx-1]+dp[idx+1][j];
                maxi=max(maxi,cost);
            }
            dp[i][j]=maxi;
        }
    }
    return dp[1][n];
}