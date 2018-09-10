#include <iostream>
using namespace std;

int arr[100001];
int dp[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        dp[i] = arr[i];
    }

    for (int i = 1; i < N; i++) {
        if (dp[i] < dp[i] + dp[i - 1]) {
            dp[i] += dp[i - 1];
        }
    }

    int ans = dp[0];
    for (int i = 0; i < N; i++) {
        if (ans < dp[i]) {
            ans = dp[i];
        }
    }
    cout << ans << '\n';

    return 0;
}