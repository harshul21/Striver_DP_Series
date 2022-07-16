//Youtube Link:- https://www.youtube.com/watch?v=nVG7eTiD2bY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=33
//Problem Link:- https://leetcode.com/problems/distinct-subsequences/

//Bottom Up
class Solution {
public:
    int dfs(int i,int j,string s,string t, vector<vector<int>> &dp){
        if(j<0){
            return 1;
        }
        if(i<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            return dp[i][j]=dfs(i-1,j,s,t,dp)+dfs(i-1,j-1,s,t,dp);
        }
        return dp[i][j]=dfs(i-1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return dfs(n-1,m-1,s,t,dp);
    }
};

//Top Down
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<double>> dp(n+1,vector<double>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
};

//Space Optimisation (2 1D array)
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<double> prev(m+1,0), curr(m+1,0);
        
        prev[0]=curr[0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    curr[j]=prev[j]+prev[j-1];
                }
                else{
                    curr[j]=prev[j];
                }
            }
            prev=curr;
        }
        return (int)prev[m];
    }
};

//Space Optimisation:- 1D
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<double> prev(m+1,0);
        
        prev[0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1]==t[j-1]){
                    prev[j]=prev[j]+prev[j-1];
                }
            }
        }
        return (int)prev[m];
    }
};