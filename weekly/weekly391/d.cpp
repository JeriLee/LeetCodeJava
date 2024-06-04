
class Solution {
public:
  class Point {
  public:
    int maxDis;
    int maxP1;
    int maxP2;
  };

  class Node {
  public:
    int kValue;
    int pIndex;
    Node(int a, int b) {
      kValue = a;
      pIndex = b;
    }
    bool operator<(const Node& rhs) const {
      return kValue < rhs.kValue;
    }
    Node() {

    }
  };
  int minimumDistance(vector<vector<int>>& points) {
    Point p = getBestK(points, -1);

    Point p2 = getBestK(points, p.maxP1);

    Point p3 = getBestK(points, p.maxP2);

    return p2.maxDis > p3.maxDis ? p3.maxDis : p2.maxDis;
  }

  Point getBestK(vector<vector<int>>& points, int invalidP) {
    Point p1 = getK1(points, invalidP);
    Point p2 = getK2(points, invalidP);

    Point best = p1.maxDis > p2.maxDis ? p1 : p2;
    return best;
  }

  Point getK1(vector<vector<int>>& points, int invalidP) {
    return getK(points, [](int x,int y) { return x + y; }, invalidP);
  }

  Point getK2(vector<vector<int>>& points, int invalidP) {
    return getK(points, [](int x, int y) { return x - y; }, invalidP);
  }

  Point getK(vector<vector<int>>& points, function<int(int, int)>&& func, int invalidP) {
    int size = points.size();
    vector<Node> kValue;

    for (int i = 0; i < size; ++i) {
      if (i == invalidP) continue;
      auto point = points[i];
      kValue.emplace_back(func(point[0], point[1]), i);
    }

    sort(kValue.begin(), kValue.end());
    int maxDis = -1;
    int maxP1 = 0;
    int maxP2 = kValue.size() - 1;
    int dis = abs(kValue[maxP1].kValue - kValue[maxP2].kValue);
    maxDis = dis;

    Point p;
    p.maxDis = maxDis;
    p.maxP1 = kValue[maxP1].pIndex;
    p.maxP2 = kValue[maxP2].pIndex;
    return p;
  }
};