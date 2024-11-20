// See https://aka.ms/new-console-template for more information

Console.WriteLine("Hello, World!");
List<int> arr = new List<int>() { 2, 5, 7, 8, 9, 2, 3, 4, 3, 1 };
List<int> arr2 = new List<int>() { -15, 19 };
List<int> arr3 = new List<int>() { -15, 3, 16, 0 };
new Solution().HasIncreasingSubarrays(arr,3);



public class Solution {
  public int MaxIncreasingSubarrays(IList<int> nums) {
    int last = 0;
    int curr = 0;
    int result = 0;
    for(int i = 0; i< nums.Count; ++i ) {
      if (curr == 0 || nums[i] > nums[i - 1]) {
        ++curr;
      } else {
        last = curr;
        curr = 1;
      }
      result = Math.Max(result, curr / 2);
      result = Math.Max(result, Math.Min(curr, last));
    }
    return result;
  }
}