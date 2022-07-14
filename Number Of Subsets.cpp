//Youtube Link:- https://www.youtube.com/watch?v=ZHyb-A2Mte4&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=18
//Problem Link:- https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

//Bottom Up Approach
int dfs(int idx,vector<int> &nums,vector<vector<int>> &dp,int target){
    if(target==0){
        return 1;
    }
    if(idx==0){
        if(nums[0]==target){
            return 1;
        }
        return 0;
    }
    if(dp[idx][target]!=-1){
        return dp[idx][target];
    }
    int ntake=dfs(idx-1,nums,dp,target);
    int take=0;
    if(target>=nums[idx]){
        take=dfs(idx-1,nums,dp,target-nums[idx]);
    }
    return dp[idx][target]=ntake+take;
}
int findWays(vector<int> &num, int tar)
{
    int n=num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,-1));
    return dfs(n-1,num,dp,tar);
}

//Top Down Approach
int findWays(vector<int> &num, int tar)
{
    int n=num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
    if(num[0]<=tar){
        dp[0][num[0]]=1;
    }
    for(int idx=1;idx<n;idx++){
        for(int sum=0;sum<=tar;sum++){
            int ntake=dp[idx-1][sum];
            int take=0;
            if(sum>=num[idx]){
                take=dp[idx-1][sum-num[idx]];
            }
            dp[idx][sum]=ntake+take;
        }
    }
    return dp[n-1][tar];
}

//Space Optimisation of top down approach
// int dfs(int idx,vector<int> &nums,vector<vector<int>> &dp,int target){
//     if(target==0){
//         return 1;
//     }
//     if(idx==0){
//         if(nums[0]==target){
//             return 1;
//         }
//         return 0;
//     }
//     if(dp[idx][target]!=-1){
//         return dp[idx][target];
//     }
//     int ntake=dfs(idx-1,nums,dp,target);
//     int take=0;
//     if(target>=nums[idx]){
//         take=dfs(idx-1,nums,dp,target-nums[idx]);
//     }
//     return dp[idx][target]=ntake+take;
// }
int findWays(vector<int> &num, int tar)
{
    int n=num.size();
    vector<int> prev(tar+1,0), curr(tar+1);
    prev[0]=curr[0]=1;
    if(num[0]<=tar){
        prev[num[0]]=1;
    }
    for(int idx=1;idx<n;idx++){
        for(int sum=0;sum<=tar;sum++){
            int ntake=prev[sum];
            int take=0;
            if(sum>=num[idx]){
                take=prev[sum-num[idx]];
            }
            curr[sum]=ntake+take;
        }
        prev=curr;
    }
    return prev[tar];
}