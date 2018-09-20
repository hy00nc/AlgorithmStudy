#include <iostream>
using namespace std;

int a[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
 
    for (int i = 0; i < M; i++) {
        scanf("%d", &a[i]);
    }

    if (N < M) {
        cout << N << '\n';
        return 0;
    }

    long long left = 0;
    long long right = 2000000000 * 10000;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long end = N;
        for (int i = 0; i < M; i++) {
            end += mid / a[i];
        }
        long long start = end;
        for (int i = 0; i < M; i++) {
            if (mid % a[i] == 0) {
                start -= 1;
            }
        }
        start += 1;

        if (N < start) {
            right = mid - 1;
        } else if (N > end) {
            left = mid + 1;
        } else {
            for (int i = 0; i < N; i++) {
                if (mid % a[i] == 0) {
                    if (N == start) {
                        cout << i + 1 << '\n';
                        return 0;
                    } else {
                        start += 1;
                    }
                }
            }
        }
    }

    return 0;
}