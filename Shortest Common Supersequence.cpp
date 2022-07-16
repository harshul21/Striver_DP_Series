//Youtbe Link:- https://www.youtube.com/watch?v=xElxAuBcvsU&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=32
//Problem Link:- https://www.codingninjas.com/codestudio/problems/shortest-supersequence_4244493?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

//Top Down Approach
#include<bits/stdc++.h>
string shortestSupersequence(string a, string b)
{
    int n=a.length();
    int m=b.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 or j==0){
                dp[i][j]=0;
            }
            else if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    string ans="";
    int i=n;
    int j=m;
    while(i>0 and j>0){
        if(a[i-1]==b[j-1]){
            ans+=a[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            ans+=a[i-1];
            i--;
        }
        else{
            ans+=b[j-1];
            j--;
        }
    }
    
    while(i>0){
        ans+=a[i-1];
        i--;
    }
    while(j>0){
        ans+=b[j-1];
        j--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
    
}