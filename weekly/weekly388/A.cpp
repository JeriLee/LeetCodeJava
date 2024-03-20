class Solution {
public:
  int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
    int sum = 0;
    for (int i = 0; i < apple.size(); ++i) {
      sum += apple[i];
    }

    sort(capacity.begin(), capacity.end());

    int sum2 = 0;
    for (int i = capacity.size() - 1; i >= 0; --i) {
      sum2 += capacity[i];
      if (sum2 >= sum) {
        return capacity.size() - i;
      }
    }
    return 0;
  }
};
