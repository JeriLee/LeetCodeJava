/*
无限背包
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        int MAX = 0x3f3f3f3f;
        for(int i = 0; i<=amount; ++i) dp[i] = MAX;
        dp[0] = 0;

        for (int i = 0; i <coins.size(); ++i) {
            int coin = coins[i];
            for(int v = coin; v <= amount; ++v) {
                dp[v] = min(dp[v], dp[v-coin] + 1);
            }
        }
        return dp[amount] == MAX ? -1 : dp[amount];
    }
};