#include <iostream>
using namespace std;

int W, H;
int map[51][51];
bool isVisited[51][51];
int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

void dfs(int x, int y) {
    isVisited[x][y] = true;

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < W && 0 <= ny && ny < H) {
            if (map[nx][ny] && !isVisited[nx][ny]) {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> H >> W && !(W == 0 && H == 0)) {
        for (int i = 0; i < W; i++) {
            for (int j = 0; j < H; j++) {
                cin >> map[i][j];
                isVisited[i][j] = false;
            }
        }

        int cnt = 0;
        for (int i = 0; i < W; i++) {
            for (int j = 0; j < H; j++) {
                if (map[i][j] && !isVisited[i][j]) {
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}