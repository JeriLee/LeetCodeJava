//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;


class Solution {
public:
  long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
    vector<int> vis;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 1) vis.push_back(i);
    }

    vector<long long> pre;

    long long num = 0;
    pre.push_back(0);
    for (int i = 0; i < vis.size(); ++i) {
      pre.push_back(num += vis[i]);
    }

    if (maxChanges > k)  maxChanges = k;

    long long ans = 123456789012345L;
    for (int currentChanges = maxChanges; currentChanges >= 0 && currentChanges >= maxChanges - 3; --currentChanges) {
      int usedC = k - currentChanges;

      for (int l = 0; l + usedC <= vis.size(); ++l) {
        if (usedC > 0) {
          long long r = l + usedC - 1;

          long long mid = (r + l) / 2;
          long long stepC = (mid + 1 - l) * vis[mid] - (pre[mid + 1] - pre[l]);
          long long stepC2 = (pre[r + 1] - pre[mid+1]) - (r - mid) * vis[mid];
          int stepSet = currentChanges * 2;
          long long ansStep = stepSet + stepC + stepC2;
          if (ansStep < ans) ans = ansStep;
        }

        if (usedC == 0) {
          int stepSet = currentChanges * 2;
          long long ansStep = stepSet;
          if (ansStep < ans) ans = ansStep;
        }
      }
    }

    return ans;
  }
};

//int main()
//{ 
//  vector<int> a = {1,1,0,0,0,1,1,0,0,1};
//  Solution* sol = new Solution();
//  sol->minimumMoves(a, 3, 1);
//
//  a = { 0,0,0,0 };
//  sol->minimumMoves(a, 2,3);
//  return 0;
//}
