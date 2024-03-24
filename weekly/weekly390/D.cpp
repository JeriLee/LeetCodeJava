#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <cassert>

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>

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

//const int maxn = 1024;
//
//class Node {
//public:
//  int index;
//  long long v;
//  Node(int index, long long v) :index(index), v(v) {}
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

//class StrNode {
//public:
//  string s;
//  int id;
//
//  StrNode(string& str, int id2) {
//    s = str;
//    id = id2;
//  }
//
//  bool operator < (const StrNode& rhs) const {
//    if (s == rhs.s) {
//      if (s.length() != rhs.s.length()) {
//        return s.length() < rhs.s.length();
//      }
//      return id < rhs.id;
//    }
//    bool v = s.compare(rhs.s);
//    return v;
//  }
//};

class TrieNode {
public:
  char c;
  int nextNodeId[26] = {};
  int minId = 0x3f3f3f3f;
  int minLen = 0x3f3f3f3f;
};

class Trie {
public:
  vector<TrieNode> tree;
  Trie() {
    tree.push_back(TrieNode());
  }

  void add(string& s, int id, int len) {
    TrieNode& node = *(tree.begin());
    add(s, id, len, 0, 0);
  }

  void add(string& s, int id, int len, int index, int nowIndex) {
    if (len < tree[nowIndex].minLen) {
      tree[nowIndex].minId = id;
      tree[nowIndex].minLen = len;
    }
    else if (len == tree[nowIndex].minLen && tree[nowIndex].minId > id) {
      tree[nowIndex].minId = id;
      tree[nowIndex].minLen = len;
    }

    if (len == index) {
      return ;
    }

    char c = s[index]-'a';
    if (tree[nowIndex].nextNodeId[c] > 0) {
      int nextId = tree[nowIndex].nextNodeId[c];
      add(s, id, len, index + 1, nextId);
    }
    else {
      tree.push_back(TrieNode());
      tree[nowIndex].nextNodeId[c] = tree.size() - 1;
      TrieNode& nextNode = tree[tree.size() - 1];
      nextNode.c = c + 'a';
      add(s, id, len, index + 1, tree.size() - 1);
    }
  }

  int get(string& s) {
    return get(s, s.length(), 0, tree[0]);
  }

  int get(string& s, int len, int index, TrieNode& nodeNode) {
    if (index == len) {
      return nodeNode.minId;
    }
    char c = s[index] - 'a';
    if (nodeNode.nextNodeId[c] > 0) {
      int nextId = nodeNode.nextNodeId[c];
      TrieNode& nextNode = tree[nextId];
      return get(s , len, index + 1, nextNode);
    }
    return nodeNode.minId;
  }
};
class Solution {
public:
  string getRe(string& s) {
    string s2 = s;
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
      char c = s2[i];
      s2[i] = s2[j];
      s2[j] = c;
    }
    return s2;
  }
  vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
    vector<int> ans;
    Trie tree;
    for (int i = 0; i < wordsContainer.size(); ++i) {
      string s = getRe(wordsContainer[i]);
      
      tree.add(s, i, s.length());
    }

    for (string& qs:wordsQuery) {
      string s = getRe(qs);
      ans.push_back(tree.get(s));
    }
    return ans;
  }
};


int main()
{
  vector<int> a = { 2,3,2,1 };
  vector<int> b = { 3,2,-3,1 };

  vector<int> a2 = { 5,5,3 };
  vector<int> b2 = { 2,-2,1 };

  vector<vector<int>> aa = { {7,6,3}, {6,6,1} };

  string s = "bcbbbcba";
  string s2 = "eebadadbfa";

  vector<string> vs1 = { "abcd","bcd","xbcd" };
  vector<string> vs2 = { "cd","bcd","xyz" };

  vector<string> vs3 = { "abcdefgh", "poiuygh", "ghghgh" };
  vector<string> vs4 = { "gh", "acbfgh", "acbfegh" };
  Solution().stringIndices(vs3, vs4);

  return 0;
}
