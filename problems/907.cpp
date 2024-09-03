/*
907
方法一：
求每个数字左右比他小的第一个数字，然后就可以计算以这个值为最小值的区间了
使用单调递增堆栈的办法
*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        stack<int> st, ste;

        int prev[n];
        int last[n];

        for(int i = 0; i < n; ++i) {
            int v = arr[i];

            while (st.size() > 0 && arr[st.top()] >= v) {
                st.pop();
            }

            if (st.size() != 0) {
                prev[i] = st.top() + 1;
            } else {
                prev[i] = 0;
            }

            st.push(i);
        }

        st = ste;
        for(int i = n-1; i >= 0 ; --i) {
            int v = arr[i];

            while (st.size() > 0 && arr[st.top()] > v) {
                st.pop();
            }

            if (st.size() != 0) {
                last[i] = st.top() - 1;
            } else {
                last[i] = n-1;
            }

            st.push(i);
        }

        long long mod = 1e9 + 7;
        long long result = 0;
        for(int i = 0; i < n; ++i) {
            result = (result + (last[i] - i + 1L) * (i - prev[i] + 1L) * arr[i])% mod;
        }
        return (int) result;
    }
};