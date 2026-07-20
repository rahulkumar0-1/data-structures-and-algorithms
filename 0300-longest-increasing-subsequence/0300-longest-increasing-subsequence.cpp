class Solution {
public:
    int solve(int ind, int preInd, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind == nums.size())
            return 0;
        if (dp[ind][preInd + 1] != -1)
            return dp[ind][preInd + 1];
        int notTake = solve(ind + 1, preInd, nums, dp);
        int take = 0;
        if (preInd == -1 || nums[ind] > nums[preInd]) {
            take = 1 + solve(ind + 1, ind, nums, dp);
        }
        return dp[ind][preInd + 1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //     vector<vector<int>> dp(n,vector<int>(n+1,-1));
        //   return solve(0,-1,nums,dp);
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        int maxx = 0;
        for (int i = 0; i < n; i++) {
            maxx = max(maxx, dp[i]);
        }
        return maxx;
    }
};