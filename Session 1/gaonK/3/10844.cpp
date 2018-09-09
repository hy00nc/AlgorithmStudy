#include <iostream>
using namespace std;

#define MOD 1000000000

long long arr[101][10];

int main() {
    int N;
    cin >> N;
    
    for (int i = 1; i <= 9; i++) {
        arr[1][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            int left = j - 1;
            int right = j + 1;

            if (left >= 0) {
                arr[i][j] += arr[i - 1][left];
            }
            if (right < 10) {
                arr[i][j] += arr[i - 1][right];
            }
            arr[i][j] %= MOD;
        }
    }

    long long ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans += arr[N][i];
    }
    cout << ans % MOD << '\n';

    return 0;
}