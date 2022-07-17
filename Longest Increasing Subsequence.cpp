//Youtube Link:- https://www.youtube.com/watch?v=IFfYfonAFGc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=43
//Problem Link:- https://leetcode.com/problems/longest-increasing-subsequence/

//Bottom Up Approach
class Solution {
public:
    int dfs(int idx,int prev_idx,vector<int>arr,int n, vector<vector<int>> &dp){
        if(idx==n){
            return 0;
        }
        if(dp[idx][prev_idx+1]!=-1){
            return dp[idx][prev_idx+1];
        }
        int len=0+dfs(idx+1,prev_idx,arr,n,dp);
        if(prev_idx==-1 or arr[idx]>arr[prev_idx]){
            len=max(len,1+dfs(idx+1,idx,arr,n,dp));
        }
        return dp[idx][prev_idx+1]=len;
    }
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        
        return dfs(0,-1,arr,n,dp);
    }
};

//Top Down Approach
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int idx=n-1;idx>=0;idx--){
            for(int prev_idx=idx-1;prev_idx>=-1;prev_idx--){
                int len=0+dp[idx+1][prev_idx+1];
                if(prev_idx==-1 || nums[idx]>nums[prev_idx]){
                    len=max(len,1+dp[idx+1][idx+1]);
                }
                dp[idx][prev_idx+1]=len;
            }
        }
        return dp[0][0];
    }
};

//Sace Optimisation 2 1D array
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> next(n+1,0), curr(n+1,0);
        for(int idx=n-1;idx>=0;idx--){
            for(int prev_idx=idx-1;prev_idx>=-1;prev_idx--){
                int len=0+next[prev_idx+1];
                if(prev_idx==-1 || nums[idx]>nums[prev_idx]){
                    len=max(len,1+next[idx+1]);
                }
                curr[prev_idx+1]=len;
            }
            next=curr;
        }
        return next[0];
    }
};

//Space Optimisation 1D array
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int  n=nums.size();
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i]){
                    dp[i]=max(dp[i],1+dp[prev]);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};
