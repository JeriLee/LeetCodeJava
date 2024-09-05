//很有意思，当k >= n+m-3时候，是可以剪枝的，因为可以直线通过。

class Node{
    public:
    int x;
    int y;
    int k;
    int step;

    Node(int x, int y, int k, int step) {
        this->x = x;
        this->y = y;
        this->k = k;
        this->step = step;
    }
};

class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    bool isInMaze(int x, int y, int n, int m) {
        return x>=0 && y>=0 && x<n && y<m;
    }

    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        if (k >= n+m-3) {
            return n-2+m-2+2;
        }

        int dp[n][m][k+1];

        memset(dp ,0x3f, sizeof(dp));

        dp[0][0][0] = 0;
        queue<Node> q;
        q.push(Node(0,0,0,0));

        while(q.size() > 0) {
            Node cur = q.front(); q.pop();
            if(dp[cur.x][cur.y][cur.k] < cur.step) continue;
            if (cur.x == n-1 && cur.y == m-1) return cur.step;
            for(int i = 0;i<4;++i) {
                int nextX = cur.x + dx[i];
                int nextY = cur.y + dy[i];
                
                if (isInMaze(nextX,nextY, n, m) == false) continue;

                int nextK = grid[nextX][nextY] == 1 ? cur.k+1 : cur.k;

                if(nextK>k) continue;
                int nextStep = cur.step + 1;
                if(dp[nextX][nextY][nextK] > nextStep) {
                    dp[nextX][nextY][nextK] = nextStep;
                    q.push(Node(nextX, nextY, nextK, nextStep));
                }
            }
        }
        return -1;
    }
};