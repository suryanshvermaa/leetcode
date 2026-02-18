class Solution {
public:
    vector<int> dp;
    int f(int n,int sum){
        if(sum>n) return -1e9;
        if(sum==n) return 1;
        if(dp[sum]!=-1) return dp[sum];
        int value=-1e9;
        for(int i=1;i<n;i++){
            int ans=f(n,sum+i);
            if(ans!=-1e9) value=max(value,i*ans);
        }
        return dp[sum]=value;
    }
    int integerBreak(int n) {
        if(n==2) return 1;
        dp.resize(58*10,-1);
        return f(n,0);
    }
};