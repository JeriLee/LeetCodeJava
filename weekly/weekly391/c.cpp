typedef long long LL;

class Solution {
public:
  // if [0,1,1,1] 
  // answer is 7 [0] [1] [1] [1] [0,1] [0,1] [0,1]
  //long long countAlternatingSubarrays2(vector<int>&  nums) {
  //  int len = nums.size();

  //  LL end0Count = 0;
  //  LL end1Count = 0;
  //  for (int& c : nums) {
  //    if (c == 1) {
  //      end1Count += end0Count + 1;
  //    }
  //    else {
  //      end0Count += end1Count + 1;
  //    }
  //  }
  //  return end0Count + end1Count;
  //}

  // if [0,1,1,1] 
  // answer is 3 [0] [1] [0,1]
  //long long countAlternatingSubarrays3(vector<int>& nums) {
  //  int len = nums.size();

  //  LL end0Len = 0;
  //  LL end1Len = 0;
  //  for (int& c : nums) {
  //    if (c == 1) {
  //      if (end1Len == 0) {
  //        end1Len = 1;
  //      }
  //      end1Len = max(end1Len, end0Len + 1);
  //    }
  //    else {
  //      if (end0Len == 0) {
  //        end0Len = 1;
  //      }

  //      end0Len = max(end0Len, end1Len + 1);
  //    }
  //  }
  //  return end0Len + end1Len;
  //}


  // if [0,1,1,1] 
  // answer is 5 [0] [1] [1] [1] [0,1]

  long long countAlternatingSubarrays(vector<int>& nums) {
    int size = nums.size();

    int last = -1;
    int len = 0;
    LL sum = 0;
    for (int index = 0; index < size; ++index) {
      if (nums[index] != last) {
        last = nums[index];
        len += 1;
        sum += len;
      }
      else {
        len = 1;
        sum += len;
      }
      last = nums[index];
    }

    return sum;
  }
};