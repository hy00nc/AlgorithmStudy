#include <iostream>
#include <queue>
using namespace std;

int map[1001][1001];
int isVisited[1001][1001];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> M >> N;
    
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            isVisited[i][j] = -1;

            if (map[i][j] == 1) {
                q.push(pair<int, int>(i, j));
                isVisited[i][j] = 0;
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

            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (!map[nx][ny] && isVisited[nx][ny] == -1) {
                    q.push(pair<int, int>(nx, ny));
                    isVisited[nx][ny] = isVisited[x][y] + 1;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!map[i][j] && isVisited[i][j] == -1) {
                cout << -1 << '\n';
                return 0;
            }
            if (!map[i][j] && isVisited[i][j]) {
                if (ans < isVisited[i][j]) {
                    ans = isVisited[i][j];
                }
            }
        }
    }
    cout << ans << '\n';
    
    return 0;
}