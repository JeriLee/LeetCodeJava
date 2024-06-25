class Solution {
    public long findKthSmallest(int[] coins, int k) {
        int n = coins.length;
        int n2 = 1 << n;
        long coinLcm[] = new long[n2];
        Arrays.fill(coinLcm, 1);
        for(int c = 1; c < n2 ; ++c) {
            for(int coinIndex = 0; coinIndex < n; ++coinIndex) {
                if ((c & (1 << coinIndex)) != 0) {
                    coinLcm[c] = lcm(coinLcm[c], coins[coinIndex]);
                }
            }
        }

        long l = 1, r = Long.MAX_VALUE / 3;

        while(l < r) {
            long mid = (l + r) >>1;
            long lessOrEqualCount = lessOrEqual(mid, coinLcm);
            if (lessOrEqualCount< k) {
                l = mid + 1;
            } else if(lessOrEqualCount > k) {
                r = mid -1;
            } else {
                r = mid;
            }
        }
        return l;
    }

    long lessOrEqual(long value, long coinLcm[]) {
        long curCount = 0;
        for (int index = 1; index < coinLcm.length; ++index) {
            var eachCoinLcm = coinLcm[index];
            curCount += value / eachCoinLcm * (Integer.bitCount(index) % 2 * 2 - 1);
        }
        return curCount;
    }

    long lcm(long a, long b) {
        return a / gcd(a,b) * b;
    }

    long gcd(long a, long b) {
        return a < b ? gcd(b,a) : b == 0 ? a : gcd(b, a%b);
    }
}