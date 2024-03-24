const int maxn = 1024;
class Solution {
public:
  int maximumLengthSubstring(string s) {
    int a[26] = {};
    int num2_count = 0;
    int left = 0;

    int maxLen = 0;
    for (int i = 0; i < s.length(); ++i) {
      char c = s[i];
      if ((a[c - 'a'] += 1) >= 3) {
        while (true) {
          a[s[left] - 'a'] --;
          if (s[left] == c) {
            ++left;
            break;
          }
          ++left;
        }
      }
      maxLen = max(maxLen, i - left + 1);
    }
    return maxLen;
  }
};