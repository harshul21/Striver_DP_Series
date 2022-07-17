//Youtube Link:- https://www.youtube.com/watch?v=ZmlQ3vgAOMo&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=35
//Problem Link:- https://leetcode.com/problems/wildcard-matching/

//Bottom Up Approach
class Solution {
public:
    bool dfs(int i,int j,string &pattern,string &text, vector<vector<int>> &dp){
        if(i<0 and j<0){
            return true;
        }
        if(i<0 and j>=0){
            return false;
        }
        if(j<0 and i>=0){
            for(int ii=0;ii<=i;ii++){
                if(pattern[ii]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(pattern[i]==text[j] or pattern[i]=='?'){
            return dp[i][j]=dfs(i-1,j-1,pattern,text,dp);
        }
        if(pattern[i]=='*'){
            return dp[i][j]=dfs(i-1,j,pattern,text,dp) | dfs(i,j-1,pattern,text,dp);
        }
        return dp[i][j]=false;
    }   
    bool isMatch(string s, string p) {
        int n=p.length();
        int m=s.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return dfs(n-1,m-1,p,s,dp);
    }
};

//Top Down Approach
