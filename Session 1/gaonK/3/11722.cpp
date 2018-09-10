#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001];

int main() {
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (arr[j] > arr[i]) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (ans < dp[i]) {
            ans = dp[i];
        }
    }
    cout << ans << '\n';
    
    return 0;
}