  class Solution {
  public:
    int minOperations(int k) {
      int a[] = { 0,0,1,2,2,3,3,4,4,4 };
      if (k <= 9) {
        return a[k];
      }

      int k2 = k / 2;
      int ans = k - 1;
      for (int i = 2; i <= k2; ++i) {
        int j = k / i;
        int yu = k - i * j;
        int ans2 = i + j - 2 + (yu > 0 ? 1 :0);
        if (ans > ans2)  ans = ans2;
      }
      return ans;
    }
  };