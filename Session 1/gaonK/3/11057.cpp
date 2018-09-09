#include <iostream>
using namespace std;

#define MOD 10007

int arr[1001][10];

int main() {
    int N;
    cin >> N;

    for (int i = 0; i <= 9; i++) {
        arr[1][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= j; k++) {
                arr[i][j] += arr[i - 1][k] % MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans += arr[N][i];
    }

    cout << ans % MOD << '\n';

    return 0;
}