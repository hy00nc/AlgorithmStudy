#include <cstdio>

char board[4000][7000];

void draw(int x, int y, int n) {
    if (n == 3) {
        board[x][y] = '*';
        board[x + 1][y - 1] = '*';
        board[x + 1][y + 1] = '*';
        for (int i = y - 2; i <= y + 2; i++) {
            board[x + 2][i] = '*';
        }
        return;
    }

    draw(x, y, n / 2);
    draw(x + n / 2, y - n / 2, n / 2);
    draw(x + n / 2, y + n / 2, n / 2);
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N; j++) {
            board[i][j] = ' ';
        }
    }

    draw(0, N - 1, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}