class Solution {
public:
  int sumOfTheDigitsOfHarshadNumber(int x) {
    int pre = x;
    int sum = 0;
    while (x > 0) {
      sum += x % 10;
      x /= 10;
    }
    return pre % sum == 0 ? sum : -1;
  }
};