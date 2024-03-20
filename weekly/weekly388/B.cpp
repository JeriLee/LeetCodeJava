class Solution {
public:
  long long maximumHappinessSum(vector<int>& happiness, int k) {
    long long ans = 0;
    sort(happiness.begin(), happiness.end());

    for (int i = happiness.size() - 1; i >= 0 && k -- > 0; --i) {
      long long hap = happiness[i];
      hap -= happiness.size() - i - 1;
      ans += hap > 0 ? hap : 0;
    }
    return ans;
  }
};