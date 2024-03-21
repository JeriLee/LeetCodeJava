#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//class Node {
//public:
//  int index, v;
//  int need = 0;
//  Node(int index, int v) :index(index), v(v) {}
//
//  bool operator < (const Node& rhs) const {
//    if (v != rhs.v) return v < rhs.v;
//    return index < rhs.index;
//  }
//};
//
//bool compare(const Node& a, const Node& b) {
//  return a.index < b.index;
//}



















////feima xiao dingli
//
//const long long mod = 1e9 + 7;
//const int CMAXN = 105;
//long long C[CMAXN][CMAXN];
//
//void init() {
//  for (int i = 0; i < CMAXN; ++i) {
//    for (int j = 0; j <= i; ++j) {
//      if (!j) C[i][j] = 1;
//      else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
//    }
//  }
//}
//
//bool is_init = false;
//
//long long getC(int a, int b) {
//  if (is_init == false) {
//    is_init = true;
//    init();
//  }
//  return C[a][b];
//}

const int maxn = 1e4 + 10;
class Solution {
public:
  long long maximumStrength(vector<int>& nums, int k) {
    vector<int> f;
    for (int i = k, p = 1; i > 0; --i, p = -p) {
      f.push_back(i * p);
    }

    long long dp[maxn][2] = {0};
    int fsize = f.size();
    for (int kindex = 0; kindex < fsize; ++kindex) {
      long long currentk = f[kindex];

      for (int num_index = 0; num_index < nums.size(); ++num_index) {
        dp[num_index][0] = LLONG_MIN / 3;

        int now_num = nums[num_index];

        if (num_index == 0) {
          if (kindex > 0) continue;
          else {
            dp[num_index][0] = nums[num_index] * currentk;
          }


          continue;
        }
        dp[num_index][0] = max(dp[num_index][0], dp[num_index - 1][1] + nums[num_index] * currentk);
        dp[num_index][0] = max(dp[num_index][0], dp[num_index - 1][0] + nums[num_index] * currentk);
      }
      for (int num_index = 0; num_index < nums.size(); ++num_index) {
        if (num_index == 0) {
          dp[num_index][1] = dp[num_index][0];
        }
        else {
          dp[num_index][1] = max(dp[num_index][0], dp[num_index - 1][1]);
        }
      }

    }

    long long ans = LLONG_MIN / 3;
    for (int i = 0; i < nums.size(); ++i) {
      if (ans < dp[i][1]) {
        ans = dp[i][1];
      }
    }
    return ans;
  }
};

int main()
{ 
  vector<int> a = { 1,2,3,-1,2 };
  vector<int> b = { -1000000000,-100000000,-10000000,123,234 };

  //Solution().maximumStrength(a, 3);
  Solution().maximumStrength(b, 5);
  return 0;
}
