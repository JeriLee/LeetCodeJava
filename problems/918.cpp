/*
这个题目很有意思，需要考虑数组首位各有一部分的结果，此时不选择中间的一部分。

针对这个循环问题，我们采用DP
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int n2 = n*2;

        int maxSum = nums[0];
        int sum = 0;
        int ed = -1;
        for(int i = 0; i < n; ++i) {
            sum+= i < n ?nums[i] : nums[i-n];
            maxSum = max(maxSum, sum);
            if (sum<=0 || i-ed >= n) {
                sum = 0;
                ed = i;
            }
        }

        int preMax[n];
        sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            if (i == 0) preMax[0] = sum;
            else preMax[i] = max(preMax[i-1], sum);
        }

        int lasMax[n];
        sum = 0;
        for(int i = n-1; i >= 0; --i) {
            sum += nums[i];
            if (i == n-1) lasMax[i] = sum;
            else lasMax[i] = max(lasMax[i+1], sum);
        }

        for (int i = 0; i<n-1; ++i) {
            if (preMax[i] >= 0 && lasMax[i+1] >= 0) {
                maxSum = max(maxSum, preMax[i] + lasMax[i+1]);
            } else if (preMax[i] >= 0) {
                maxSum = max(maxSum, preMax[i] + 0);
            } else if (lasMax[i+1] >= 0) {
                maxSum = max(maxSum, lasMax[i+1] + 0);
            } else {
                maxSum = max(maxSum, preMax[i]);
                maxSum = max(maxSum, lasMax[i+1]);
            } 
        }
        return maxSum;
    }
};