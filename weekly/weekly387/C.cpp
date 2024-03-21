class Solution {
public:
  int minimumOperationsToWriteY(vector<vector<int>>& grid) {
    vector<int> y_count = { 0,0,0 };
    vector<int> other_count = { 0,0,0 };

    int n = grid.size();
    int mid = grid.size() / 2;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int v = grid[i][j];
        if (isY(n, mid, i, j)) {
          y_count[v] += 1;
        }
        else {
          other_count[v] += 1;
        }
      }
    }

    int sum = n * n;
    int maa = 0;
    for (int i = 0; i <= 2; ++i) {
      for (int j = 0; j <= 2; ++j) {
        if (i == j) continue;
        maa = max(maa, y_count[i] + other_count[j]);
      }
    }
    return sum - maa;
  }

  bool isY(int n, int mid, int x, int y) {
    if (x <= mid && x == y) return true;
    if (x <= mid && x + y == n - 1) return true;
    if (x >= mid && y == mid) return true;
    return false;
  }
};