#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int board[26][26];
int isVisited[26][26];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void dfs(int x, int y, int mark) {
    isVisited[x][y] = mark;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < N && 0 <= ny && ny < N) {
            if (board[nx][ny] && !isVisited[nx][ny]) {
                dfs(nx, ny, mark);
            }
        } 
    }
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &board[i][j]);
        }
    }

    int mark = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] && !isVisited[i][j]) {
                dfs(i, j, ++mark);
            }
        }
    }

    printf("%d\n", mark);
    vector<int> count;
    for (int k = 1; k <= mark; k++) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (isVisited[i][j] == k) {
                    cnt++;
                }
            }
        }
        count.push_back(cnt);
    }
    sort(count.begin(), count.end());
    for (int x : count) {
        printf("%d\n", x);
    }

    return 0;
}