//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//

class Solution {
public:
  class Node {
  public:
    int index, v;
    Node(int index, int v):index(index), v(v) {}

    bool operator < (const Node& rhs) const {
      if (v != rhs.v) return v < rhs.v;
      return index < rhs.index;
    }
  };

  vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
    vector<Node> nodes;
    int n = nums.size();
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      nodes.push_back(Node(i, nums[i]));
      sum += nums[i];
    }

    sort(nodes.begin(), nodes.end());

    vector<bool> vis(n);
    int min_index = 0;

    vector<long long> ans;
    for (vector<int>& q: queries) {
      int q0 = q[0];
      int q1 = q[1];

      if (vis[q0] == false) {
        vis[q0] = true;
        sum -= nums[q0];
      }

      while (min_index < n && q1 > 0) {
        int nextIndex = nodes[min_index].index;
        if (vis[nextIndex] == false) {
          vis[nextIndex] = true;
          sum -= nums[nextIndex];
          ++min_index;
          --q1;
        }
        else {
          ++min_index;
        }
      }

      ans.push_back(sum);
    }

    return ans;
  }
};
//int main()
//{ 
//  vector<int> a = { 1,2,2,1,2,3,1 };
//  vector<vector<int>> b = { {1,2}, {3,3},{4,2} };
//
//  Solution().unmarkedSumArray(a, b);
//  return 0;
//}
