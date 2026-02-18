class Solution {
public:
    vector<vector<long long>> dp;
    bool f(vector<int>& nums,int target,int i,int sum){
        if(sum==target) return true;
        if(sum>target) return false;
        if(i<0) return false;
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool take=f(nums,target,i-1,sum+nums[i]);
        bool notTake=f(nums,target,i-1,sum);
        return dp[i][sum]=take||notTake;
    }
    bool canPartition(vector<int>& nums) {
        long long int sum=0;
        for(auto &el:nums) sum+=el;
        if(sum%2==1) return false;
        dp.resize(nums.size(),vector<long long>(sum,-1));
        int target=sum/2;
        return f(nums,target,nums.size()-1,0);
    }
};