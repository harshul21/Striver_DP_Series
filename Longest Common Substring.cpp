//Youtube Link:- https://www.youtube.com/watch?v=_wP9mWNPL5w&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=28
//Problem Link:- https://www.codingninjas.com/codestudio/problems/longest-common-substring_1235207?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

//Top Down Approach or Tabulation
int lcs(string &str1, string &str2){
    int n=str1.length();
    int m=str2.length();
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    int ans=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 or j==0){
                dp[i][j]=0;
            }
            else if(str1[i-1]==str2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                ans=max(ans,dp[i][j]);
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    return ans;
}

//Space Optimisation
int lcs(string &str1, string &str2){
    int n=str1.length();
    int m=str2.length();
    vector<int> prev(m+1,0),curr(m+1,0);
    int ans=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 or j==0){
                curr[j]=0;
            }
            else if(str1[i-1]==str2[j-1]){
                curr[j]=1+prev[j-1];
                ans=max(ans,curr[j]);
            }
            else{
                curr[j]=0;
            }
        }
        prev=curr;
    }
    return ans;
}
