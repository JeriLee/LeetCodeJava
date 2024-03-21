class Solution {
public:
  vector<int> resultArray(vector<int>& nums) {
    vector<int> a;
    vector<int> b;

    for (const int& x : nums) {
      if (a.size() == 0) a.push_back(x);
      else if (b.size() == 0) b.push_back(x);
      else {
        if (*a.rbegin() > *b.rbegin()) {
          a.push_back(x);
        }
        else {
          b.push_back(x);
        }
      }
    }

    a.insert(a.end(), b.begin(), b.end());
    return a;
  }
};