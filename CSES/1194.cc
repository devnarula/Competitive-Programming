#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<vector<int>> monsterDist(n, vector<int>(m, INT_MAX));
    queue<pair<int,int>> mq;
    pair<int,int> start;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                monsterDist[i][j] = 0;
                mq.push({i, j});
            }
            else if (grid[i][j] == 'A') {
                start = {i, j};
            }
        }
    }

    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    char moveChar[4] = {'R', 'D', 'L', 'U'};

    while (!mq.empty()) {
        auto [r, c] = mq.front(); mq.pop();
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (grid[nr][nc] == '#' || monsterDist[nr][nc] <= monsterDist[r][c] + 1)
                continue;
            monsterDist[nr][nc] = monsterDist[r][c] + 1;
            mq.push({nr, nc});
        }
    }

    vector<vector<int>> playerDist(n, vector<int>(m, -1));
    map<pair<int,int>, pair<char,pair<int,int>>> parent;
    queue<pair<int,int>> pq;

    playerDist[start.first][start.second] = 0;
    pq.push(start);

    bool found = false;
    pair<int,int> endCell;

    while (!pq.empty() && !found) {
        auto [r, c] = pq.front(); pq.pop();
        if (r == 0 || r == n - 1 || c == 0 || c == m - 1) {
            found = true;
            endCell = {r, c};
            break;
        }
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (grid[nr][nc] == '#' || playerDist[nr][nc] != -1) continue;
            if (playerDist[r][c] + 1 >= monsterDist[nr][nc]) continue;
            playerDist[nr][nc] = playerDist[r][c] + 1;
            parent[{nr, nc}] = {moveChar[d], {r, c}};
            pq.push({nr, nc});
        }
    }

    if (!found) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    vector<char> path;
    auto cur = endCell;
    while (cur != start) {
        auto [mv, p] = parent[cur];
        path.push_back(mv);
        cur = p;
    }
    reverse(path.begin(), path.end());
    cout << path.size() << "\n";
    for (char ch : path) cout << ch;
    cout << "\n";

    return 0;
}
