class Solution {
    public int minimumOperations(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        int count[][] = new int[10][m];
        for (int i = 0; i < 10; ++i)
            for(int j = 0; j < m; ++j)
            count[i][j] = 0;

        for (int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int v = grid[i][j];
                count[v][j] += 1;
            }
        }

        int dp[][] = new int[10][m];
        for (int i = 0; i < 10; ++i)
            for(int j = 0; j < m; ++j)
                dp[i][j] = 0x3f3f3f3f;

        for (int i = 0; i < 10; ++i) {
            dp[i][0] = n - count[i][0];
        }

        for(int j = 1; j<m; ++j) {
            for(int v = 0; v < 10; ++v) {
                for(int lastV = 0; lastV<10; ++lastV) {
                    if (v == lastV) continue;
                    dp[v][j] = Math.min(dp[v][j], n - count[v][j] + dp[lastV][j - 1]);
                }
            }
        }

        int best = dp[0][m-1];
        for (int v = 0; v <10; ++v) {
            best = Math.min(best, dp[v][m-1]);
        }

        return best;
    }
}