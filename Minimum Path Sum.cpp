//Youtube Link:- https://www.youtube.com/watch?v=_rgTlyky1uQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=11
//Problem Link:- https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

//Solution with memoisation

int dfs(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp){
    if(i<0 or j<0){
        return 1e9;
    }
    if(i==0 and j==0){
        return grid[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    int up=grid[i][j]+dfs(i-1,j,grid,dp);
    int left=grid[i][j]+dfs(i,j-1,grid,dp);
    
    return dp[i][j]=min(up,left);
}
int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return dfs(n-1,m-1,grid,dp);
}

//Tabulation
int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 and j==0){
                dp[i][j]=grid[0][0];
            }
            else{
                int up=grid[i][j];
                if(i>0){
                    up+=dp[i-1][j];
                }
                else{
                    up+=1e9;
                }
                int left=grid[i][j];
                if(j>0){
                    left+=dp[i][j-1];
                }
                else{
                    left+=1e9;
                }
                dp[i][j]=min(up,left);
            }
        }
    }
    return dp[n-1][m-1];
}

//Space Optimisation
int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<int> prev(m,0);
    for(int i=0;i<n;i++){
        vector<int> curr(m,0);
        for(int j=0;j<m;j++){
            if(i==0 and j==0){
                curr[i]=grid[i][j];
            }
            else{
                int up=grid[i][j];
                if(i>0){
                    up+=prev[j];
                }
                else{
                    up+=1e9;
                }
                
                int left=grid[i][j];
                if(j>0){
                    left+=curr[j-1];
                }
                else{
                    left+=1e9;
                }
                curr[i]=min(up,left);
            }
        }
        prev=curr;
    }
    return prev[m-1];
}