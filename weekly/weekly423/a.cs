// See https://aka.ms/new-console-template for more information

Console.WriteLine("Hello, World!");
List<int> arr = new List<int>() { 2, 5, 7, 8, 9, 2, 3, 4, 3, 1 };
List<int> arr2 = new List<int>() { -15, 19 };
List<int> arr3 = new List<int>() { -15, 3, 16, 0 };
new Solution().HasIncreasingSubarrays(arr,3);



public class Solution {
  public bool HasIncreasingSubarrays(IList<int> nums, int k) {
    int lastMaxLen = 0;
    int currMaxLen = 0;
    bool finded = false;
    for (int i = 0; i < nums.Count; i++) {
      if (currMaxLen == 0 || nums[i] > nums[i-1]) {
        ++currMaxLen;
      } else {
        if (currMaxLen >= k*2) {
          finded = true;
        }
        if (lastMaxLen == 0) {
          lastMaxLen = currMaxLen;
          currMaxLen = 1;
        } else {
          if (lastMaxLen >= k && currMaxLen >= k) {
            finded = true;
          }
          lastMaxLen = currMaxLen;
          currMaxLen = 1;
        }
      }
    }

    if (currMaxLen > 0) {
      if (currMaxLen >= k * 2) {
        finded = true;
      }
      if (lastMaxLen == 0) {
        lastMaxLen = currMaxLen;
      } else {
        if (lastMaxLen >= k && currMaxLen >= k) {
          finded = true;
        }
        lastMaxLen = currMaxLen;
      }
    }
    return finded;
  }
}


