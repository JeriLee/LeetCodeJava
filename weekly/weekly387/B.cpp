const int maxn = 1024;
class Solution {
public:
  int countSubmatrices(vector<vector<int>>& grid, int k) {
    int n = grid.size();
    int m = grid[0].size();

    long long pre[maxn] = {};
    long long g_pre[maxn] = {};
    long long k_long = k;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      vector<int>& row = grid[i];
      for (int j = 0; j < m; ++j) {
        if (j == 0) pre[j] = row[j];
        else pre[j] = pre[j - 1] + row[j];
      }

      for (int j = 0; j < m; ++j) {
        if ((g_pre[j] += pre[j]) <= k_long) {
          ++ans;
        }
      }
    }
    return ans;
  }
};

int main()
{ 
  vector<int> a = { 1,2,3,-1,2 };
  vector<int> b = { -1000000000,-100000000,-10000000,123,234 };

  vector<vector<int>> aa = { {7,6,3}, {6,6,1} };

  Solution().countSubmatrices(aa, 18);

  return 0;
}
