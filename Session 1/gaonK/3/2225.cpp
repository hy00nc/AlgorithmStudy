#include <iostream>
using namespace std;

#define MOD 1000000000

long long dp[201][201];

int main() {
    int N, K;
    cin >> N >> K;

    for (int i = 0; i <= N; i++) {
        dp[i][1] = 1;
    }

    for (int i = 2; i <= K; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k <= j; k++) {
                dp[j][i] += dp[k][i - 1];
            }
            dp[j][i] %= MOD;
        }
    }
    cout << dp[N][K] % MOD << '\n';

    return 0;
}