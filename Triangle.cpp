//Youtube Link:- https://www.youtube.com/watch?v=SrP-PiLSYC0&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=12
//Problem Link:- https://www.codingninjas.com/codestudio/problems/triangle_1229398?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

//Recursive Approach
int dfs(int i,int j,vector<vector<int>>& triangle,int n){
    if(i==n-1){
        return triangle[n-1][j];
    }
    int d=triangle[i][j]+dfs(i+1,j,triangle,n);
    int dg=triangle[i][j]+dfs(i+1,j+1,triangle,n);
    return min(d,dg);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
    return dfs(0,0,triangle,n);
}

//Memoization
int dfs(int i,int j,vector<vector<int>>& triangle,int n,vector<vector<int>> &dp){
    if(i==n-1){
        return triangle[n-1][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int d=triangle[i][j]+dfs(i+1,j,triangle,n,dp);
    int dg=triangle[i][j]+dfs(i+1,j+1,triangle,n,dp);
    return dp[i][j]=min(d,dg);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return dfs(0,0,triangle,n,dp);
}

//Space Optimisation of recursion stack space or Bottom Up Approach
int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int j=0;j<n;j++){
        dp[n-1][j]=triangle[n-1][j];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int d=triangle[i][j]+dp[i+1][j];
            int dg=triangle[i][j]+dp[i+1][j+1];\
            dp[i][j]=min(d,dg);
        }
    }
    return dp[0][0];
}

//Space Optimisation
int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<int> front(n,0),curr(n,0);
    for(int j=0;j<n;j++){
        front[j]=triangle[n-1][j];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int d=triangle[i][j]+front[j];
            int dg=triangle[i][j]+front[j+1];
            curr[j]=min(d,dg);
        }
        front=curr;
    }
    return front[0];
}