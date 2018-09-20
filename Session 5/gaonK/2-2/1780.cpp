#include <iostream>
using namespace std;

int paper[3000][3000];
int ans[3];

void cut(int n, int x, int y) {
    if (n == 0) {
        return;
    }

    bool flag = true;
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (paper[i][j] != paper[x][y]) {
                flag = false;
                break;
            }
        }
        if (!flag) break;
    }

    if (flag) {
        ans[paper[x][y] + 1]++; 
    } else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cut(n / 3, x + (n / 3) * i, y + (n / 3) * j);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    cut(N, 0, 0);

    for (int i = 0; i < 3; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}