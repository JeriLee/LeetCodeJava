//using namespace std::set;
// 题目不值得看
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> se = set<int>();
        
        for(int i = 0; i < nums.size(); ++i) {
            int v = nums[i];
            if (se.count(v) > 0) {
                return true;
            }
            se.insert(v);
        }
        return false;
    }
};