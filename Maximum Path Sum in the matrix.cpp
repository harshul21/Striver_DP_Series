//Youtube Link:- https://www.youtube.com/watch?v=N_aJ5qQbYA0&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=13
//Problem Link:- https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

//Normal Recursive Code
int func(int i,int j,vector<vector<int>> &matrix){
    if(j<0 or j>=matrix[0].size()) return -1e8;
    if(i==0) return matrix[0][j];
    
    int up=matrix[i][j]+func(i-1,j,matrix);
    int ld=matrix[i][j]+func(i-1,j-1,matrix);
    int rd=matrix[i][j]+func(i-1,j+1,matrix);
    
    return max(up,max(ld,rd));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    int maxi=-1e8;
    for(int j=0;j<m;j++){
        maxi=max(maxi,func(n-1,j,matrix));
    }
    return maxi;
}

//Memoization or Top Down Approach
int func(int i,int j,vector<vector<int>> &matrix,vector<vector<int>> &dp){
    if(j<0 or j>=matrix[0].size()) return -1e8;
    if(i==0) return matrix[0][j];
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int up=matrix[i][j]+func(i-1,j,matrix,dp);
    int ld=matrix[i][j]+func(i-1,j-1,matrix,dp);
    int rd=matrix[i][j]+func(i-1,j+1,matrix,dp);
    
    return dp[i][j]=max(up,max(ld,rd));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    int maxi=-1e8;
    vector<vector<int>> dp(n,vector<int>(m,-1));
    for(int j=0;j<m;j++){
        maxi=max(maxi,func(n-1,j,matrix,dp));
    }
    return maxi;
}

//Bottom Up Approach
//Stack Space Optimisation
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    int maxi=-1e8;
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int j=0;j<m;j++){
        dp[0][j]=matrix[0][j];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int u=matrix[i][j]+dp[i-1][j];
            int ld=matrix[i][j];
            if(j-1>=0) ld+=dp[i-1][j-1];
            else ld+=-1e8;
           
            int rd=matrix[i][j];
            if(j+1<m) rd+=dp[i-1][j+1];
            else rd+=-1e8;
            
            dp[i][j]=max(u,max(ld,rd));
        }
    }
    for(int j=0;j<m;j++){
        maxi=max(maxi,dp[n-1][j]);
    }
    return maxi;
}

//Space Optimisation

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    int maxi=-1e8;
    vector<int> prev(m,0),curr(m,0);
    for(int j=0;j<m;j++){
        prev[j]=matrix[0][j];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int u=matrix[i][j]+prev[j];
            int ld=matrix[i][j];
            if(j-1>=0) ld+=prev[j-1];
            else ld+=-1e8;
           
            int rd=matrix[i][j];
            if(j+1<m) rd+=prev[j+1];
            else rd+=-1e8;
            
            curr[j]=max(u,max(ld,rd));
        }
        prev=curr;
    }
    for(int j=0;j<m;j++){
        maxi=max(maxi,prev[j]);
    }
    return maxi;
}