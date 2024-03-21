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




// pre sum
    //vector<long long> pre;
    //int sum = 0;
    //for (int i = 0; i < nums.size(); ++i) {
    //  pre.push_back(sum += nums[i]);
    //}

  //long long getSum(vector<int>& pre, int l, int r) {
  //  if (l == r) return 0;
  //  if (l == 0) return pre[r];
  //  return pre[r] - pre[l - 1];
  //}

const int maxn = 1024;
class Solution {
public:

};

int main()
{ 
  vector<int> a = { 1,2,3,-1,2 };
  vector<int> b = { -1000000000,-100000000,-10000000,123,234 };

  vector<vector<int>> aa = { {7,6,3}, {6,6,1} };

  Solution();

  return 0;
}
