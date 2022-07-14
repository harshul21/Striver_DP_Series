///Same Ques as partition with given difference just language change
///Youtube Link:- https://www.youtube.com/watch?v=b3GD8263-PQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=22
//Problem Link:- https://www.codingninjas.com/codestudio/problems/target-sum_4127362?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
int func(int idx,vector<int>&arr,int target, vector<vector<int>> &dp){
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
    return dp[idx][target]=(ntake+take);
}
int targetSum(int n, int target, vector<int>& arr) {
    int sum=0;
    for(auto it:arr){
        sum+=it;
    }
    if(sum-target<0 or (sum-target)%2){
        return 0;
    }
    int find=(sum-target)/2;
    vector<vector<int>> dp(n,vector<int>(find+1,-1));
    return func(n-1,arr,find,dp);
}
