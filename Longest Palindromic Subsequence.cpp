//Youtube Link:- https://www.youtube.com/watch?v=6i_T5kkfv4A&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=29
//Problem Link:- https://leetcode.com/problems/longest-palindromic-subsequence/

//Top Down Approach
class Solution {
public:
    int longest(string s1,string s2,int n){
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0 or j==0){
                    dp[i][j]=0;
                }
                else if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
    int longestPalindromeSubseq(string s) {
        string s1=s;
        int n=s.length();
        reverse(s.begin(),s.end());
        return longest(s1,s,n);
    }
};

