//Youtube Link:- https://www.youtube.com/watch?v=mLfjzJsN8us&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=3
//Problem Link:- https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include<bits/stdc++.h>
int dp(long long currStep,long long nStairs,int *dp1){
    if(currStep>nStairs){
        return 0;
    }
    if(dp1[currStep]!=-1){
        return dp1[currStep];
    }
    if(currStep==nStairs){
        return 1;
    }
    
    int oneStep=dp(currStep+1,nStairs,dp1);
    int twoStep=dp(currStep+2,nStairs,dp1);
    
    return dp1[currStep]=oneStep+twoStep;
}
int countDistinctWayToClimbStair(long long nStairs)
{
    int dp1[nStairs+1];
    memset(dp1,-1,sizeof(dp1));
    return dp(0,nStairs,dp1);
}