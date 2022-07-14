//Youtube Link:- https://www.youtube.com/watch?v=GqOmJHQZivw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=20
//Problem Link:- https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

//Bottom Up Approach
int dfs(int idx,int W, vector<int> wt, vector<int> val, vector<vector<int>> &dp){
    if(idx==0){
        if(wt[0]<=W){
            return val[0];
        }
        return 0;
    }
    if(dp[idx][W]!=-1){
        return dp[idx][W];
    }
    int ntake=dfs(idx-1,W,wt,val,dp);
    int take=INT_MIN;
    if(wt[idx]<=W){
        take=val[idx]+dfs(idx-1,W-wt[idx],wt,val,dp);
    }
    return dp[idx][W]=max(take,ntake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
    return dfs(n-1,maxWeight,weight,value,dp);
}

//Top Down Approach
int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
    for(int i=wt[0];i<=maxWeight;i++){
        dp[0][i]=val[0];
    }
    for(int idx=1;idx<n;idx++){
        for(int W=0;W<=maxWeight;W++){
            int ntake=dp[idx-1][W];
            int take=INT_MIN;
            if(wt[idx]<=W){
                take=val[idx]+dp[idx-1][W-wt[idx]];
            }
            dp[idx][W]=max(take,ntake); 
        }
    }
    return dp[n-1][maxWeight];
}

//Space Optimisation
int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
    vector<int> prev(maxWeight+1,0),curr(maxWeight+1,0);
    for(int i=wt[0];i<=maxWeight;i++){
        prev[i]=val[0];
    }
    for(int idx=1;idx<n;idx++){
        for(int W=0;W<=maxWeight;W++){
            int ntake=prev[W];
            int take=INT_MIN;
            if(wt[idx]<=W){
                take=val[idx]+prev[W-wt[idx]];
            }
            curr[W]=max(take,ntake); 
        }
        prev=curr;
    }
    return prev[maxWeight];
}

//Space Optimisation:- Single Array
int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
    vector<int> prev(maxWeight+1,0);
    for(int i=wt[0];i<=maxWeight;i++){
        prev[i]=val[0];
    }
    for(int idx=1;idx<n;idx++){
        for(int W=maxWeight;W>=0;W--){
            int ntake=prev[W];
            int take=INT_MIN;
            if(wt[idx]<=W){
                take=val[idx]+prev[W-wt[idx]];
            }
            prev[W]=max(take,ntake); 
        }
    }
    return prev[maxWeight];
}