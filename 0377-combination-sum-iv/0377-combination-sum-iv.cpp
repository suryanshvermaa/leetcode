class Solution {
public:
    vector<int> dp;
    int f(vector<int>& nums, int target,int sum){
        int n=nums.size();
        if(sum>target) return 0;
        if(sum==target) return 1;
        if(dp[sum]!=-1) return dp[sum];
        int cnt=0;
        for(int j=0;j<n;j++){
            cnt+=f(nums,target,sum+nums[j]);
        }
        return dp[sum]=cnt;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int maxEl=*max_element(nums.begin(),nums.end());
        dp.resize(target*10,-1);
        return f(nums,target,0);
    }
};