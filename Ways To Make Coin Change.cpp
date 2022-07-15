//Yotube Link:- https://www.youtube.com/watch?v=HgyouUi11zk&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=23
//Problem Link:- https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471?leftPanelTab=0

//Bottom Up
#include<bits/stdc++.h>
long dfs(int idx,int *denominations,int value, vector<vector<long>> &dp){
    
    if(idx==0){
        return (value%denominations[idx]==0);
    }
    if(dp[idx][value]!=-1){
        return dp[idx][value];
    }
    long ntake=dfs(idx-1,denominations,value,dp);
    long take=0;
    if(denominations[idx]<=value){
        take=dfs(idx,denominations,value-denominations[idx],dp);
    }
    return dp[idx][value]= ntake+take;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n,vector<long>(value+1,-1));
    return dfs(n-1,denominations,value,dp);
}

//Top Down
#include<bits/stdc++.h>
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n,vector<long>(value+1,0));
    for(int i=0;i<=value;i++){
        dp[0][i]=(i%denominations[0]==0);
    }
    for(int idx=1;idx<n;idx++){
        for(int j=0;j<=value;j++){
            long ntake=dp[idx-1][j];
            long take=0;
            if(denominations[idx]<=j){
                take=dp[idx][j-denominations[idx]];
            }
            dp[idx][j]= ntake+take;
        }
    }
    
    return dp[n-1][value];
}

//Space Optimisation
#include<bits/stdc++.h>
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<long> prev(value+1,0),curr(value+1,0);
    for(int i=0;i<=value;i++){
        prev[i]=(i%denominations[0]==0);
    }
    for(int idx=1;idx<n;idx++){
        for(int j=0;j<=value;j++){
            long ntake=prev[j];
            long take=0;
            if(denominations[idx]<=j){
                take=curr[j-denominations[idx]];
            }
            curr[j]= ntake+take;
        }
        prev=curr;
    }
    
    return prev[value];
}