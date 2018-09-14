#include <cstdio>

int a[51][51];
int b[51][51];

void flip(int x, int y) {
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            a[i][j] = 1 - a[i][j];
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &a[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &b[i][j]);
        }
    }

    int ans = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 2; j++) {
            if (a[i][j] != b[i][j]) {
                flip(i, j);
                ans++;
            }
        }
    }

    bool flag = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] != b[i][j]) {
                flag = false;
                break;
            }
        }
        if (!flag) break;
    }
    
    if (flag) {
        printf("%d\n", ans);
    } else {
        printf("-1\n");
    }

    return 0;
}