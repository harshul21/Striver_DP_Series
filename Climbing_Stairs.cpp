//Youtube Link:- https://www.youtube.com/watch?v=mLfjzJsN8us&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=3
//Problem Link:- https://leetcode.com/problems/climbing-stairs/
//Bottom Up Approach
class Solution {
public:
    int func(int n,vector<int> &dp){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int left=func(n-1,dp);
        int right=func(n-2,dp);
        
        return dp[n]=left+right;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return func(n,dp);
    }
};

//Top Down Approach or Tabulation to save the stack space of recursion
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        for(int i=0;i<=n;i++){
            if(i==0){
                dp[0]=1;
            }
            else{
                int left=0;
                if(i-1>=0){
                    left=dp[i-1];
                }
                int right=0;
                if(i-2>=0){
                    right=dp[i-2];
                }
                dp[i]=right+left;
            }
        }
        return dp[n];
    }
};