#include <iostream>
using namespace std;

int arr[101];

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        long long ans = 0;
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                ans += gcd(arr[i], arr[j]);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}