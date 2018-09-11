#include <cstdio>
#include <queue>
using namespace std;

int N, M;
int map[101][101];
int isVisited[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    queue<pair<int, int>> q;
    q.push(pair<int, int>(0, 0));
    isVisited[0][0] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (map[nx][ny] && !isVisited[nx][ny]) {
                    q.push(pair<int, int>(nx, ny));
                    isVisited[nx][ny] = isVisited[x][y] + 1;
                }
            }
        }
    }   
    printf("%d\n", isVisited[N - 1][M - 1]);

    return 0;
}