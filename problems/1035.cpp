/*
很普通的二维DP
*/

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int dp[n+1][m+1];
        for (int i = 0; i <= n ; ++i) {
            for(int j = 0 ; j <= m ; ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                    continue;
                }

                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if (nums1[i-1] == nums2[j-1]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
                }
            }
        }
        return dp[n][m];
    }
};