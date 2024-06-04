





class Pre {
public:
  int len;
  long long* pre;
  Pre(const vector<int>& source) {
    len = source.size();
    pre = new long long[source.size()];
    long long sum = 0;
    for (int i = 0; i < source.size(); ++i) {
      *(pre + i) = sum += source[i];
    }
  }

  //[L, R]
  long long getSum(int l, int r) {
    if (l == r) return 0;
    if (l == 0) return pre[r];
    long long value = (pre[r] - pre[l - 1]);
    return value;
  }

  static void test() {
    vector<int> source;

    for (int i = 0; i <= 100; ++i)
      source.push_back(i);
    Pre pre(source);
    std::cout << pre.getSum(1, 100) << endl;
  }
};