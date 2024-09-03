/*
	note:
	贪心，按照每个区间左边界排序，然后遍历一遍合并区间即可
*/

class Solution {
public:
  static bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) {
      return a[1] < b[1];
    }
    else {
      return a[0] < b[0];
    }
  }

  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), cmp);

    int l = intervals[0][0];
    int r = intervals[0][1];

    vector<vector<int>> result;
    for (int i = 1; i < intervals.size(); ++i) {
      int cl = intervals[i][0];
      int cr = intervals[i][1];

      if (cl <= r) {
        r = std::max(cr, r);
      }
      else {
        vector<int> rangeX = { l, r };
        result.push_back(rangeX);
        l = cl;
        r = cr;
      }
    }

    vector<int> rangeX = { l, r };
    result.push_back(rangeX);


    return result;
  }
};