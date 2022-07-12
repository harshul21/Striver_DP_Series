//Youtube Link:- https://www.youtube.com/watch?v=TmhpgXScLyY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=10
//Problem Link:- https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

//Normal Recursive Code
int func(int i,int j,vector<vector<int>>  mat){
    if(i>=0 and j>=0 and mat[i][j]==-1){
        return 0;
    }
    if(i==0 and j==0){
        return 1;
    }
    if(i<0 or j<0){
        return 0;
    }
    int left=func(i-1,j,mat);
    int right=func(i,j-1,mat);
    
    return left+right;
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    return func(n-1,m-1,mat);
}

//Using dp
int mod=(int)(1e9+7);
int func(int i,int j,vector<vector<int>>  mat, vector<vector<int>> &dp){
    if(i>=0 and j>=0 and mat[i][j]==-1){
        return 0;
    }
    
    if(i==0 and j==0){
        return 1;
    }
    if(i<0 or j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int left=func(i-1,j,mat,dp);
    int right=func(i,j-1,mat,dp);
    
    return dp[i][j]=(left+right)%mod;
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return func(n-1,m-1,mat,dp);
}

//Tabulation
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    int dp[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==-1){
                dp[i][j]=0;
            }
            else if(i==0 and j==0){
                dp[i][j]=1;
            }
            else{
                int up=0,left=0;
                if(i>0){
                    up=dp[i-1][j];
                }
                if(j>0){
                    left=dp[i][j-1];
                }
                dp[i][j]=(left+up)%mod;
            }
        }
    }
    return dp[n-1][m-1];
}