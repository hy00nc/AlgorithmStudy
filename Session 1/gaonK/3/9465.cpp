#include <iostream>
#include <algorithm>
using namespace std;

int board[2][100001];
long long dp[3][100001];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> board[i][j];
            }
        }

        dp[0][1] = board[0][1];
        dp[1][1] = board[1][1];

        for (int i = 2; i <= N; i++) {
            dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]) + board[0][i];
            dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + board[1][i];
            dp[2][i] = max(dp[0][i - 1], max(dp[1][i - 1], dp[2][i - 1]));
        }

        long long ans = 0;
        for (int i = 0; i < 3; i++) {
            if (ans < dp[i][N]) {
                ans = dp[i][N];
            }
        }

        cout << ans << '\n';
    }

    return 0;
}