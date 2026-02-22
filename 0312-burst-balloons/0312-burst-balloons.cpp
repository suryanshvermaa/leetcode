class Solution {
public:
    vector<vector<int>> dp;
    int f(vector<int>& nums,int i,int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        for(int k=i;k<=j;k++){
            ans=max(ans,nums[i-1]*nums[k]*nums[j+1]+f(nums,i,k-1)+f(nums,k+1,j));
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int> newNums;
        newNums.push_back(1);
        dp.resize(n+2,vector<int>(n+2,-1));
        for(int i=0;i<n;i++) newNums.push_back(nums[i]);
        newNums.push_back(1);
        return f(newNums,1,n);
    }
};