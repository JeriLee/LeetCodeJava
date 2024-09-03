/*
907
方法一：
求每个数字左右比他小的第一个数字，然后就可以计算以这个值为最小值的区间了
使用单调递增堆栈的办法

方法二：
动态规划
遍历 i from [0, n-1]
计算以i结尾的所有数字和 dp[i]
dp[i] = k * arr[i] + dp[i-k]
*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        stack<int> st, ste;

        long long mod = 1e9 + 7;
        long long result = 0;
        vector<int> dp(n);

        for(int i = 0; i < n; ++i) {
            int v = arr[i];
            while(st.size() > 0 && arr[st.top()] > v) {
                st.pop();
            }

            int k = st.size() > 0 ? i - st.top() : i - (-1);
            int needExtend = st.size() > 0 ? dp[st.top()] : 0;
            dp[i] = k * v + needExtend;
            dp[i] %= mod;
            st.push(i);
        }

        for (int i = 0; i < n; ++i) {
            result += dp[i];
            result %= mod;
        }
        return (int) result;
    }
};