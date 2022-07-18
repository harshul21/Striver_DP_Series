//Youtube Link:- https://www.youtube.com/watch?v=YY8iBaYcc4g&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=46
//Problem Link:- https://www.codingninjas.com/codestudio/problems/longest-string-chain_3752111?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

//Bottom up
bool checkpossible(string s1,string s2){
    
    if(s1.size()!=s2.size()+1){
        return false;
    }
    int first=0;
    int second=0;
    while(first<s1.size()){
        if(s1[first]==s2[second]){
            first++;
            second++;
        }
        else{
            first++;
        }
    }
    return (first==s1.size() and second==s2.size());
}
static bool comp(string &s1, string &s2){
    return s1.size()<s2.size();
}
int longestStrChain(vector<string> &words)
{
    sort(words.begin(),words.end(),comp);
    int n=words.size();
    vector<int> dp(n,1);
    int maxi=1;
    for(int i=0;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(checkpossible(words[i],words[prev]) and  1+dp[prev]>dp[i]){
                dp[i]=1+dp[prev];
            }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
        }
    }
    return maxi;
}