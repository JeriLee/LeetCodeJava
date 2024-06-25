class Solution {

    void makeUnion(int pa, int pb, int[] p, int[] weight) {
        weight[pb] &= weight[pa];
        p[pa] = pb;
    }

    int getP(int index, int[] p, int[] weight) {
        if (p[index] == index) {
            return index;
        } else {
            var newParent = getP(p[index], p, weight);
            p[index] = newParent;
            weight[index] = weight[newParent];
            return newParent;
        }
    }

    public int[] minimumCost(int n, int[][] edges, int[][] query) {
        int[] p = new int[n];
        int[] weight = new int[n];

        for (int i = 0; i < n; ++i) {
            p[i] = i;
            weight[i] = (~0);
        }

        for (var edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int len = edge[2];

            var fromParent = getP(from, p, weight);
            var toParent = getP(to, p, weight);

            makeUnion(fromParent, toParent, p, weight);
            weight[toParent] &= len;
        }

        int[] result = new int[query.length];
        int i = 0;
        for(var eachQ: query) {
            int from = eachQ[0];
            int to = eachQ[1];

            int p1 = getP(from, p, weight);
            int p2 = getP(to, p, weight);
            if (p1 == p2) {
                result[i] = weight[from];
            } else {
                result[i] = -1;
            }

            ++i;
        }
        return result;
    }
}

//使用并查集处理图种的连通块，每个连通块做并查集处理
//评价：考察对并查集是否完全熟悉，并且能够自主修改算法逻辑