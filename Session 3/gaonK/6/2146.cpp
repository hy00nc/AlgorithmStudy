#include <iostream>
#include <queue>
using namespace std;

int N;
int map[101][101];
int island[101][101];
int dist[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, int cnt) {
    island[x][y] = cnt;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < N && 0 <= ny && ny < N) {
            if (map[nx][ny] && !island[nx][ny]) {
                dfs(nx, ny, cnt);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            dist[i][j] = -1;
            if (map[i][j] == 1) {
                q.push(pair<int, int>(i, j));
                dist[i][j] = 0;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] && !island[i][j]) {
                dfs(i, j, ++cnt);
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                if (!map[nx][ny] && dist[nx][ny] == -1) {
                    q.push(pair<int, int>(nx, ny));
                    dist[nx][ny] = dist[x][y] + 1;
                    island[nx][ny] = island[x][y];
                }
            }
        }
    }   
    
    int ans = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i + 1 < N) {
                if (island[i][j] != island[i + 1][j]) {
                    if (ans == -1 || ans > dist[i][j] + dist[i + 1][j]) {
                        ans = dist[i][j] + dist[i + 1][j];
                    }
                }
            }
            if (j + 1 < N) {
                if (island[i][j] != island[i][j + 1]) {
                    if (ans == -1 || ans > dist[i][j] + dist[i][j + 1]) {
                        ans = dist[i][j] + dist[i][j + 1];
                    }
                }
            }
        }
    }
    cout << ans << '\n';

    return 0;
}