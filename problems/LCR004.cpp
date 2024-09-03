/*
数组中只有一个数字出现一次，其他都出现3次
求这个数字。

方法一：
按照位运算的位，来求这个位上是否对3取模多一个。

方法二：
改成3进制位运算，这个办法其实看起来也没那么好，起码转换三进制的时候很浪费时间，还要储存空间

*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int d = 0;d <32; ++d) {
            int count = 0;
            for(int i = 0; i < nums.size(); ++i) {
                int num = nums[i];
                if ((num&(1<<d)) != 0) {
                    ++ count;
                }
            }
            if (count %3 != 0) {
                result |= (1<<d);
            }
        }
        return result;
    }
};