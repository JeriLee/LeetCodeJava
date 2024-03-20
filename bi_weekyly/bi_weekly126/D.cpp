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



















//feima xiao dingli

const long long mod = 1e9 + 7;
const int CMAXN = 105;
long long C[CMAXN][CMAXN];

void init() {
  for (int i = 0; i < CMAXN; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (!j) C[i][j] = 1;
      else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
  }
}

bool is_init = false;

long long getC(int a, int b) {
  if (is_init == false) {
    is_init = true;
    init();
  }
  return C[a][b];
}

class Solution {
public:
  const static int maxn = 105;
  int sumOfPower(vector<int>& nums, int k) {
    int len = nums.size();
    long long a[maxn][maxn] = {};
    // a[v] [num_count] ;
    a[0][0] = 1;

    for (int num_index = 0; num_index < len; ++num_index) {
      int v = nums[num_index];

      for (int after_v = k; after_v >= 0; --after_v) {
        int before_v = after_v - v;
        if (before_v < 0) break;

        for (int before_count = 0; before_count <= num_index; ++before_count) {
          a[after_v][before_count + 1] += a[before_v][before_count];
          a[after_v][before_count + 1] %= mod;
        }
      }
    }

    long long ans = 0;
    for (int count = 0; count <= len; ++count) {
      if (a[k][count] > 0) {
        int temp = a[k][count];
        // 选择 count 个数，它们的和为k的时候，一共有temp个组合
        // count个数字是必选的
        int not_must_count = len - count;

        for (int y = 0; y <= not_must_count; ++y) {
          ans += getC(not_must_count, y) * temp;
          ans %= mod;
        }
      }
    }
    return ans;
  }
};

int main()
{ 
  vector<int> a = { 1,2,3 };
  vector<int> b = { 2,3,3 };

  //Solution().sumOfPower(a, 3);
  Solution().sumOfPower(b, 5);
  return 0;
}
