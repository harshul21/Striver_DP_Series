//Youtube Link:- https://www.youtube.com/watch?v=zoilQD1kYSg&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=19
//Problem Link:- https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

//Bottom Up
int mod=(int)(1e9+7);
int func(int idx,vector<int> &arr,int target, vector<vector<int>> &dp){
    if(idx==0){
        if(target==0 and arr[0]==0){
            return 2;
        }
        if(target==0 or target==arr[0]){
            return 1;
        }
        return 0;
    }
    if(dp[idx][target]!=-1){
        return dp[idx][target];
    }
    int ntake=func(idx-1,arr,target,dp);
    int take=0;
    if(target>=arr[idx]){
        take=func(idx-1,arr,target-arr[idx],dp);
    }
    return dp[idx][target]=(take+ntake)%mod;
}
int countPartitions(int n, int d, vector<int> &arr) {
    int sum=0;
    for(auto it:arr){
        sum+=it;
    }
    if(sum-d<0 or (sum-d)%2){
        return 0;
    }
    int find=(sum-d)/2;
    vector<vector<int>> dp(n,vector<int>(find+1,-1));
    return func(n-1,arr,find,dp);
}

//Top Down
int mod=(int)(1e9+7);
int countPartitions(int n, int d, vector<int> &arr) {
    int sum=0;
    for(auto it:arr){
        sum+=it;
    }
    if(sum-d<0 or (sum-d)%2){
        return 0;
    }
    int find=(sum-d)/2;
    vector<vector<int>> dp(n,vector<int>(find+1,0));
    if(arr[0]==0){
        dp[0][0]=2;
    }
    else{
        dp[0][0]=1;
    }
    if(arr[0]!=0 and arr[0]<=find){
        dp[0][arr[0]]=1;
    }
    for(int idx=1;idx<n;idx++){
        for(int sum=0;sum<=find;sum++){
            int ntake=dp[idx-1][sum];
            int take=0;
            if(sum>=arr[idx]){
                take=dp[idx-1][sum-arr[idx]];
            }
            dp[idx][sum]=(ntake+take)%mod;
        }
    }
    return dp[n-1][find];
}

//Space Optimisation
int mod=(int)(1e9+7);
int countPartitions(int n, int d, vector<int> &arr) {
    int sum=0;
    for(auto it:arr){
        sum+=it;
    }
    if(sum-d<0 or (sum-d)%2){
        return 0;
    }
    int find=(sum-d)/2;
    vector<int> prev(find+1,0),curr(find+1,0);
    if(arr[0]==0){
        prev[0]=2;
    }
    else{
        prev[0]=1;
    }
    if(arr[0]!=0 and arr[0]<=find){
        prev[arr[0]]=1;
    }
    for(int idx=1;idx<n;idx++){
        for(int sum=0;sum<=find;sum++){
            int ntake=prev[sum];
            int take=0;
            if(sum>=arr[idx]){
                take=prev[sum-arr[idx]];
            }
            curr[sum]=(ntake+take)%mod;
        }
        prev=curr;
    }
    return prev[find];
}