class Solution {
public:
  int maxBottlesDrunk(int numBottles, int numExchange) {
    int sum = 0;
    int used = numBottles;
    while (numBottles >= numExchange) {
      numBottles -= numExchange;
      numBottles += 1;
      used += 1;
      numExchange += 1;
    }
    return used;
  }
};

typedef long long LL;

class Solution {
public:
  int getSum(int x, int y) {
    return x == y ? x : (x + y) * (y - x + 1) / 2;
  }

  int maxBottlesDrunk(int numBottles, int numExchange) {
    long long numBottlesL = numBottles;
    long long numExchangeL = numExchange;

    long long  used = numBottlesL;
    while (numBottlesL >= numExchangeL) {
      long long R = numBottlesL / numExchangeL;
      long long L = 1;

      while (L < R) {
        LL mid = (L + R + 1) / 2;
        LL need = numExchangeL * mid + getSum(0, mid-1);
        if (numBottlesL >= need) {
          L = mid;
        }
        else if (numBottlesL < need) {
          R = mid - 1;
        }
      }

      numBottlesL -= numExchangeL * L + getSum(0, L - 1);
      numBottlesL += L;
      used += L;
      numExchangeL += L;
    }
    return used;
  }
};