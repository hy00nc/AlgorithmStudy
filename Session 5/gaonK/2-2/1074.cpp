#include <cstdio>

int ans = 0;

void draw(int n, int r, int c, int st) {
    if (n == 2) {
        ans = st + 2 * r + c;
        return;
    }

    int m = n / 2;
    if (r < m) {
        if (c < m) {
            draw(m, r, c, st);
        } else {
            draw(m, r, c - m, st + m * m);
        }
    } else {
        if (c < m) {
            draw(m, r - m, c, st + m * m * 2);
        } else {
            draw(m, r - m, c - m, st + m * m * 3);
        }
    }
}

int main() {
    int N, r, c;
    scanf("%d %d %d", &N, &r, &c);

    int n = 1 << N;
    draw(n, r, c, 0);

    printf("%d\n", ans);

    return 0;
}