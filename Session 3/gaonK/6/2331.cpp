#include <iostream>
using namespace std;

int isChecked[250000];

int multiplyKTimes(int a, int k) {
    int res = 0;
    while (a > 0) {
        int x = a % 10;
        int tmp = 1;
        for (int i = 0; i < k; i++) {
            tmp *= x;
        }
        res += tmp;
        a /= 10;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int A, K;
    cin >> A >> K;

    int cnt = 0;
    while (!isChecked[A]) {
        cnt++;
        isChecked[A] = cnt;
        A = multiplyKTimes(A, K);
    }
    int ans = isChecked[A] - 1;
    cout << ans << '\n';

    return 0;
}