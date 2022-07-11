//Youtube Link:- https://www.youtube.com/watch?v=EgG3jsGoPvQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=4
//Problem Link:- https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

//Normal DP Solution
#include<bits/stdc++.h>
int solve(int ind, vector<int>& height, vector<int>& dp){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int jumpTwo = INT_MAX;
    int jumpOne= solve(ind-1, height,dp)+ abs(height[ind]-height[ind-1]);
    if(ind>1)
        jumpTwo = solve(ind-2, height,dp)+ abs(height[ind]-height[ind-2]);
    
    return dp[ind]=min(jumpOne, jumpTwo);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    return solve(n-1,heights,dp);
}

//Bottom Up Approach with Space Optimisation
#include<bits/stdc++.h>
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,0);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int fs=dp[i-1]+abs(heights[i]-heights[i-1]);
        int ss=INT_MAX;
        if(i>1){
            ss=dp[i-2]+abs(heights[i]-heights[i-2]);
        }
        
        dp[i]=min(ss,fs);
    }
    return dp[n-1];
}