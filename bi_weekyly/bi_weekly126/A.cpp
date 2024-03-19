//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;


class Solution {
public:
  int sumOfEncryptedInt(vector<int>& nums) {
    long long sum = 0;
    for (int& num : nums) {
      if (num == 0) {
        continue;
      }

      int temp = num;
      int b = 0;
      while (temp > 0) {
        b = max(b, temp % 10);
        temp /= 10;
      }

      temp = num;
      long long num_after = 0;
      long long bei = 1;
      while (temp > 0) {
        num_after += b * bei;
        temp /= 10;
        bei *= 10;
      }
      sum += num_after;
    }
    return sum;
  }
};

//int main()
//{ 
//  return 0;
//}
