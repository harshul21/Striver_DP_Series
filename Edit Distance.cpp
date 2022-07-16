//Youtube Link:- https://www.youtube.com/watch?v=fJaKO8FbDdo&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=34
//Problem Link:- https://leetcode.com/problems/edit-distance/

//Bottom up Approach
class Solution {
public:
    int dfs(int i,int j,string s1,string s2,vector<vector<int>> &dp){
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return dp[i][j]=dfs(i-1,j-1,s1,s2,dp);
        }
        return dp[i][j]=1+min(dfs(i-1,j,s1,s2,dp),min(dfs(i,j-1,s1,s2,dp),dfs(i-1,j-1,s1,s2,dp)));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return dfs(n-1,m-1,word1,word2,dp);
    }
};

//Top Down Approach
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};

//Space Optimisation 2 1D array
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int> prev(m+1,0), curr(m+1,0);
        
        for(int j=0;j<=m;j++){
            prev[j]=j;
        }
        for(int i=1;i<=n;i++){
            curr[0]=i;
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    curr[j]=prev[j-1];
                }
                else{
                    curr[j]=1+min(prev[j],min(curr[j-1],prev[j-1]));
                }
            }
            prev=curr;
        }
        return prev[m];
    }
};

