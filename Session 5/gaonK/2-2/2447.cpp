#include <cstdio>

char board[3000][3000];

void draw(int x, int y, int n) {
    if (n == 1) {
        board[x][y] = '*';
        return;
    }

    int size = n / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) continue;
            draw(x + size * i, y + size * j, size);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = ' ';
        }
    }

    draw(0, 0, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}