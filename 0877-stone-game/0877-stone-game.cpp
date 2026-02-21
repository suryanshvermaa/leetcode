class Solution {
public:
    vector<vector<int>> dp;
    int f(vector<int>& piles,int i,int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MIN;
        // take from start
        ans=max(ans,piles[i]-f(piles,i+1,j));
        // take from last
        if(i!=j) ans=max(ans,piles[j]-f(piles,i,j-1));
        return dp[i][j]=ans;
    }
    bool stoneGame(vector<int>& piles) {
        dp.resize(piles.size(),vector<int> (piles.size(),-1));
        if(f(piles,0,piles.size()-1)>0) return true;
        return false;
    }
};