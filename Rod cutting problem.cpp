//Youtube Link:- https://www.youtube.com/watch?v=mO8XpGoJwuo&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=25
//Problem Link:- https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

//Bottom Up
int dfs(int idx,int N,vector<int> &price, vector<vector<int>> dp){
    if(idx==0){
        return N*price[0];
    }
    if(dp[idx][N]!=-1){
        return dp[idx][N];
    }
    int ntake=dfs(idx-1,N,price,dp);
    int take=INT_MIN;
    int rodlen=idx+1;
    if(N>=rodlen){
        take=price[idx]+dfs(idx,N-rodlen,price,dp);
    }
    return dp[idx][N]=max(take,ntake);
}
int cutRod(vector<int> &price, int n)
{
    int sz=price.size();
    vector<vector<int>> dp(sz,vector<int>(n+1,-1));
    return dfs(sz-1,n,price,dp);
}


//Top Down
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n,vector<int>(n+1,0));
    for(int N=0;N<=n;N++){
        dp[0][N]=N*price[0];
    }
    for(int idx=1;idx<n;idx++){
        for(int N=0;N<=n;N++){
            int ntake=dp[idx-1][N];
            int take=INT_MIN;
            int rodlen=idx+1;
            if(N>=rodlen){
                take=price[idx]+dp[idx][N-rodlen];
            }
            dp[idx][N]=max(take,ntake);
        }
    }
    return dp[n-1][n];
}

//Space Optimisation:- 2arrays
int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n+1,0),curr(n+1,0);
    for(int N=0;N<=n;N++){
        prev[N]=N*price[0];
    }
    for(int idx=1;idx<n;idx++){
        for(int N=0;N<=n;N++){
            int ntake=prev[N];
            int take=INT_MIN;
            int rodlen=idx+1;
            if(N>=rodlen){
                take=price[idx]+curr[N-rodlen];
            }
            curr[N]=max(take,ntake);
        }
        prev=curr;
    }
    return prev[n];
}

//Space Optimisation 1d array
int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n+1,0);
    for(int N=0;N<=n;N++){
        prev[N]=N*price[0];
    }
    for(int idx=1;idx<n;idx++){
        for(int N=0;N<=n;N++){
            int ntake=prev[N];
            int take=INT_MIN;
            int rodlen=idx+1; 
            if(N>=rodlen){
                take=price[idx]+prev[N-rodlen];
            }
            prev[N]=max(take,ntake);
        }
    }
    return prev[n];
}