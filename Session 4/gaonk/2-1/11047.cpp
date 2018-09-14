#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    int coin[N];
    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    int ans = 0;
    for (int i = N - 1; i >= 0; i--) {
        while (coin[i] <= K) {
            ans += K / coin[i];
            K %= coin[i];
        }
    }
    cout << ans << '\n';
    
    return 0;
}