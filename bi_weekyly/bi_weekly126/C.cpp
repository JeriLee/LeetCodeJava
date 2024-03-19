//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;

class Node {
public:
  int index, v;
  int need = 0;
  Node(int index, int v) :index(index), v(v) {}

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
  string minimizeStringValue(string s) {
    int len = s.length();
    vector<Node> vis;
    for (int i = 0; i < 26; ++i) vis.push_back(Node(i, 0));

    int need = 0;
    for (int i = 0; i < len; ++i) {
      if (s[i] == '?') ++need;
      else {
        int index = s[i] - 'a';
        vis[index].v += 1;
      }
    }

    sort(vis.begin(), vis.end());

    if (vis[25].v * 26 < len) {
      int bei = len / 26;
      int yu = len % 26;
      for (Node& node : vis) {
        if (node.index < yu) {
          node.need = bei + 1 - node.v;
        }
        else {
          node.need = bei - node.v;
        }
      }
    }
    else {
      int pre = 0;
      for (int index = 0; index < 26; ++index) {
        if (need == 0)break;
        pre += vis[index].v;
        int tian_chong = (index + 1)* vis[index].v - pre;
        if (tian_chong >= need) {
          int sum = (need + pre - vis[index].v);
          int bei = sum / index;
          int yu = sum % index;

          for (int i = 0; i < index; ++i) {
            vis[i].need = bei - vis[i].v;
          }

          int lastKey = -1;
          int minKey = 26;
          int minIndex = 0;
          while (yu-- > 0) {
            for (int i = 0; i < index; ++i) {
              if (vis[i].index > lastKey && vis[i].index < minKey) {
                minKey = vis[i].index;
                minIndex = i;
              }
            }
            vis[minIndex].need += 1;
            lastKey = minKey;
            minKey = 26;
          }
          break;
        }
      }
    }

    sort(vis.begin(), vis.end(), compare);

    string ans = s;
    int index = 0;
    for (int i = 0; i < len; ++i) {
      if (ans[i] == '?') {

        while (vis[index].need <= 0) {
          ++index;
        }
        if (vis[index].need > 0) {
          vis[index].need--;
          ans[i] = vis[index].index + 'a';
        }
      }
    }

    return ans;
  }
};
//int main()
//{ 
//  vector<int> a = { 1,2,2,1,2,3,1 };
//  vector<vector<int>> b = { {1,2}, {3,3},{4,2} };
//
//  Solution().minimizeStringValue("abcdefghijklmnopqrstuvwxy??");
//  Solution().minimizeStringValue("g?xvgroui??xk?zqb?da?jan?cdhtksme");
//  return 0;
//}
