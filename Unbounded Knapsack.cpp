//Youtube Link:- https://www.youtube.com/watch?v=OgvOZ6OrJoY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=24
//Problem Link:- https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

//Bottom Up
int dfs(int idx,int w,vector<int> &val, vector<int> &wt, vector<vector<int>> &dp){
    if(idx==0){
        return ((int)(w/wt[0]))*val[0];
    }
    if(dp[idx][w]!=-1){
        return dp[idx][w];
    }
    int ntake=dfs(idx-1,w,val,wt,dp);
    int take=0;
    if(wt[idx]<=w){
        take=val[idx]+dfs(idx,w-wt[idx],val,wt,dp);
    }
    return dp[idx][w]=max(ntake,take);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
    return dfs(n-1,w,profit,weight,dp);
}

//Top Down
int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt)
{
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));
    for(int i=0;i<=w;i++){
        dp[0][i]=((int)(i/wt[0]))*val[0];
    }
    
    for(int idx=1;idx<n;idx++){
        for(int j=0;j<=w;j++){
            int ntake=dp[idx-1][j];
            int take=0;
            if(wt[idx]<=j){
                take=val[idx]+dp[idx][j-wt[idx]];
            }
            dp[idx][j]=max(ntake,take);
        }
    }
    return dp[n-1][w];
}

//Space Optimisation two array
int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt)
{
    vector<int> prev(w+1,0), curr(w+1,0);
    for(int i=0;i<=w;i++){
        prev[i]=((int)(i/wt[0]))*val[0];
    }
    
    for(int idx=1;idx<n;idx++){
        for(int j=0;j<=w;j++){
            int ntake=prev[j];
            int take=0;
            if(wt[idx]<=j){
                take=val[idx]+curr[j-wt[idx]];
            }
            curr[j]=max(ntake,take);
        }
        prev=curr;
    }
    return prev[w];
}

//1D array space optimisation
int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt)
{
    vector<int> prev(w+1,0);
    for(int i=0;i<=w;i++){
        prev[i]=((int)(i/wt[0]))*val[0];
    }
    
    for(int idx=1;idx<n;idx++){
        for(int j=0;j<=w;j++){
            int ntake=prev[j];
            int take=0;
            if(wt[idx]<=j){
                take=val[idx]+prev[j-wt[idx]];
            }
            prev[j]=max(ntake,take);
        }
    }
    return prev[w];
}
