//Youtube Link:- https://www.youtube.com/watch?v=NPZn9jBrX8U&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=26
//Problem Link:- https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

//Bottom Up
#include<bits/stdc++.h>
int dfs(int idx1,int idx2,string s,string t, vector<vector<int>> &dp){
    if(idx1<0 or idx2<0){
        return 0;
    }
    if(dp[idx1][idx2]!=-1){
        return dp[idx1][idx2];
    }
    if(s[idx1]==t[idx2]){
        return dp[idx1][idx2]=1+dfs(idx1-1,idx2-1,s,t,dp);
    }
    return dp[idx1][idx2]=max(dfs(idx1,idx2-1,s,t,dp),dfs(idx1-1,idx2,s,t,dp));
}
int lcs(string s, string t)
{
    int n=s.size();
    int m=t.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return dfs(n-1,m-1,s,t,dp);
}

//Top Down Approach
int lcs(string s, string t)
{
    int n=s.size();
    int m=t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<=m;i++){
        dp[i][0]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[n][m];
}

//Space Optimisation
#include<bits/stdc++.h>
int lcs(string s, string t)
{
    int n=s.size();
    int m=t.size();
    vector<int> prev(m+1,0),curr(m+1,0);
    for(int i=0;i<=n;i++){
        prev[i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                curr[j]=1+prev[j-1];
            }
            else{
                curr[j]=max(curr[j-1],prev[j]);
            }
        }
        prev=curr;
    }
    return prev[m];
}