//Youtube Link:- https://www.youtube.com/watch?v=7win3dcgo3k&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=16
//Problem Link:- https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

//Bottom Up
bool dfs(vector<int> &arr,int idx,int target,vector<vector<int>> &dp){
    
    if(target==0){
        return true;
    }
    if(idx==0){
        return arr[0]==target;
    }
    if(dp[idx][target]!=-1){
        return dp[idx][target];
    }
    bool ntake=dfs(arr,idx-1,target,dp);
    bool take=false;
    if(target>=arr[idx]){
        take=dfs(arr,idx-1,target-arr[idx],dp);
    }
    
    return dp[idx][target]=ntake or take;
}
bool canPartition(vector<int> &arr, int n)
{
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum%2){
        return false;
    }
    sum=sum/2;
    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    return dfs(arr,n-1,sum,dp);
}

//Top Down
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        
        if(sum%2==1){
            return false;
        }
        
        sum=sum/2;
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        
        if(nums[0]<=sum){
            dp[0][nums[0]]=true;
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool ntake=dp[i-1][j];
                
                bool take=false;
                if(nums[i]<=j){
                    take=dp[i-1][j-nums[i]];
                }
                
                dp[i][j]= ntake || take;
            }
        }
        return dp[n-1][sum];
    }
};

//Space Optimisation of tabulation method
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        
        if(sum%2==1){
            return false;
        }
        
        sum=sum/2;
        vector<int> prev(sum+1,false);
        
        
        prev[0]=true;
        
        if(nums[0]<=sum){
            prev[nums[0]]=true;
        }
        
        for(int i=1;i<n;i++){
            vector<int> curr(sum+1,false);
            curr[0]=true;
            for(int j=1;j<=sum;j++){
                bool ntake=prev[j];
                
                bool take=false;
                if(nums[i]<=j){
                    take=prev[j-nums[i]];
                }
                
                curr[j]= ntake || take;
            }
            prev=curr;
        }
        return prev[sum];
    }
};