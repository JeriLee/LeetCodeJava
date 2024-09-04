/*
题目不难，只是写法上可以优化一下，比如排序函数使用lamda表达式，按照abs排序
*/
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [=](int& x, int& y) -> bool{
            int absx = abs(x);
            int absy = abs(y);
            if(absx != absy) return absx < absy;
            return x<y;
            });

        int n = arr.size();
        bool vis[n];
        memset(vis, 0, sizeof(bool) * n);
        int next = 1;
        for (int i = 0; i<n; ++i) {
            if(vis[i]) continue;
            int v = arr[i];
            int nextV = v * 2;

            bool finded = false;
            while(next<n) {
                if(arr[next] == nextV) {
                    finded = true;
                    break;
                } else {
                    ++next;
                }
            }

            if (finded) {
                vis[next] = true;
                ++next;
            } else {
                return false;
            }
        }

        return true;
    }
};