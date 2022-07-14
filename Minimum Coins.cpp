//Youtube Link:- https://www.youtube.com/watch?v=myPeWb3Y68A&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=21
//Problem Link:- https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=0

//Bottom Up Approach
int func(int idx,vector<int> &nums,int t,vector<vector<int>> &dp){
    if(idx==0){
        if(t%nums[0]==0){
            return t/nums[0];
        }
        return 1e9;
    }
    if(dp[idx][t]!=-1){
        return dp[idx][t];
    }
    int ntake= func(idx-1,nums,t,dp);
    int take=INT_MAX;
    if(nums[idx]<=t){
        take=1+func(idx,nums,t-nums[idx],dp);
    }
    return dp[idx][t]=min(take,ntake);
}
int minimumElements(vector<int> &num, int x)
{
    int n=num.size();
    vector<vector<int>> dp(n,vector<int>(x+1,-1));
    int ans=func(n-1,num,x,dp);
    if(ans>=1e9){
        return -1;
    }
    return ans;
}

//Top Down Approach
int minimumElements(vector<int> &num, int x)
{
    int n=num.size();
    vector<vector<int>> dp(n,vector<int>(x+1,0));
    for(int t=0;t<=x;t++){
        if(t%num[0]==0){
            dp[0][t]=t/num[0];
        }
        else{
            dp[0][t]=1e9;
        }
    }
    for(int idx=1;idx<n;idx++){
        for(int t=0;t<=x;t++){
            int ntake= dp[idx-1][t];
            int take=INT_MAX;
            if(num[idx]<=t){
                take=1+dp[idx][t-num[idx]];
            }
            dp[idx][t]=min(take,ntake);
        }
    }
    if(dp[n-1][x]>=1e9){
        return -1;
    }
    return dp[n-1][x];
}

//Space Optimisation
int minimumElements(vector<int> &num, int x)
{
    int n=num.size();
    vector<int> prev(x+1,0), curr(x+1,0);
    for(int t=0;t<=x;t++){
        if(t%num[0]==0){
            prev[t]=t/num[0];
        }
        else{
            prev[t]=1e9;
        }
    }
    for(int idx=1;idx<n;idx++){
        for(int t=0;t<=x;t++){
            int ntake= prev[t];
            int take=INT_MAX;
            if(num[idx]<=t){
                take=1+curr[t-num[idx]];
            }
            curr[t]=min(take,ntake);
        }
        prev=curr;
    }
    if(prev[x]>=1e9){
        return -1;
    }
    return prev[x];
}