class Node {
public:
  int index;
  long long v;
  Node(int index, long long v) :index(index), v(v) {}

  bool operator < (const Node& rhs) const {
    if (v != rhs.v) return v < rhs.v;
    return index < rhs.index;
  }
};

bool compare(const Node& a, const Node& b) {
  return a.index < b.index;
}


class Solution {
public:
  vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
    vector<long long> ans;
    priority_queue<Node> que;
    vector<Node> nodes;
    set<int> se;
    map<int, int> keyToIndex;
    for (int i = 0; i < nums.size(); ++i) {
      if (se.count(nums[i]) > 0) continue;
      se.insert(nums[i]);
      nodes.push_back(Node(nums[i], 0));
      que.push(Node(nums[i], 0));
    }

    sort(nodes.begin(), nodes.end(), compare);

    for (int i = 0; i < nodes.size(); ++i) {
      keyToIndex.emplace(nodes[i].index, i);
    }

    for (int i = 0; i < nums.size(); ++i) {
      int ope_v = nums[i];
      int index = keyToIndex[ope_v];
      nodes[index].v += freq[i];
      que.push(Node(nums[i], nodes[index].v));

      while (!que.empty()) {
        Node big = que.top();
        int big_index = keyToIndex[big.index];
        if (nodes[big_index].v == big.v) {
          ans.push_back(big.v);
          break;
        }
        else {
          que.pop();
        }
      }
    }
    return ans;
  }
};