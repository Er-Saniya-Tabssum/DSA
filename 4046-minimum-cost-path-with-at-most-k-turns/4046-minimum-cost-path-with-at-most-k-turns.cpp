class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        if (m == 1 && n == 1)
            return grid[0][0];

        const long long INF = 1e18;

        // Directions:
        // 0 = up, 1 = down, 2 = left, 3 = right
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        // dist[r][c][dir][turns]
        int states = m * n * 4 * (k + 1);
        vector<long long> dist(states, INF);

        auto id = [&](int r, int c, int dir, int turns) {
            return (((r * n + c) * 4 + dir) * (k + 1) + turns);
        };

        // {cost, r, c, direction, turns}
        using State = tuple<long long, int, int, int, int>;

        priority_queue<State, vector<State>, greater<State>> pq;

        // First move from (0,0) does NOT count as a turn.
        for (int dir = 0; dir < 4; dir++) {
            int nr = dr[dir];
            int nc = dc[dir];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            long long cost = grid[0][0] + grid[nr][nc];

            int idx = id(nr, nc, dir, 0);

            if (cost < dist[idx]) {
                dist[idx] = cost;
                pq.push({cost, nr, nc, dir, 0});
            }
        }

        while (!pq.empty()) {
            auto [cost, r, c, lastDir, turns] = pq.top();
            pq.pop();

            if (cost != dist[id(r, c, lastDir, turns)])
                continue;

            // Reached destination.
            // Since priority queue pops minimum cost first,
            // this is the optimal answer.
            if (r == m - 1 && c == n - 1)
                return (int)cost;

            for (int dir = 0; dir < 4; dir++) {
                int nr = r + dr[dir];
                int nc = c + dc[dir];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                int newTurns = turns + (dir != lastDir);

                if (newTurns > k)
                    continue;

                long long newCost = cost + grid[nr][nc];

                int idx = id(nr, nc, dir, newTurns);

                if (newCost < dist[idx]) {
                    dist[idx] = newCost;
                    pq.push({newCost, nr, nc, dir, newTurns});
                }
            }
        }

        return -1;
    }
};