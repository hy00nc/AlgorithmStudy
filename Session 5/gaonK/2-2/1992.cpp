#include <cstdio>
using namespace std;

int board[65][65];

void makeQuardTree(int x, int y, int n) {
    bool flag = true;
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (board[i][j] != board[x][y]) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            break;
        }
    }

    if (flag) {
        printf("%d", board[x][y]);
    } else {
        printf("(");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                makeQuardTree(x + (n / 2) * i, y + (n / 2) * j, n / 2);
            }
        }
        printf(")");
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &board[i][j]);
        }
    }
    makeQuardTree(0, 0, N);
    
    return 0;
}