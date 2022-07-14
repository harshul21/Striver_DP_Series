//Youtube Link:- https://www.youtube.com/watch?v=fWX9xDmIzRI&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=15
//Problem Link:- https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0

//Bottom Upp Approach
bool func(int idx,int target,  vector<int> &arr, vector<vector<int>> &dp){
    if(target==0){
        return true;
    }
    if(idx==0){
        return arr[0]==target;
    }
    if(dp[idx][target]!=-1){
        return dp[idx][target];
    }
    bool ntake=func(idx-1,target,arr,dp);
    bool take=false;
    if(arr[idx]<=target){
        take=func(idx-1,target-arr[idx],arr,dp);
    }
    return dp[idx][target]= ntake or take;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return func(n-1,k,arr,dp);
}

//Top Down Approach or Tabulation
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    dp[0][arr[0]]=1;
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            bool ntake=dp[i-1][j];
            bool take=false;
            if(arr[i]<=j){
                take=dp[i-1][j-arr[i]];
            }
            dp[i][j]= ntake or take;
        }
    }
    return dp[n-1][k];
}

//Space Optimisation
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<bool> prev(k+1,0),curr(k+1,0);
    prev[0]=curr[0]=true;
    prev[arr[0]]=true;
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            bool ntake=prev[j];
            bool take=false;
            if(arr[i]<=j){
                take=prev[j-arr[i]];
            }
            curr[j]= ntake or take;
        }
        prev=curr;
    }
    return prev[k];
}