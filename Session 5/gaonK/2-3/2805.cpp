#include <cstdio>

int a[1000001];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int maxLength = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
        if (a[i] > maxLength) {
            maxLength = a[i];
        }
    }

    int left = 0;
    int right = maxLength;
    int ans = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        long long sum = 0;
        for (int i = 0; i < N; i++) {
            if (a[i] > mid) {
                sum += a[i] - mid;
            }
        }

        if (sum >= M) {
            if (ans < mid) {
                ans = mid;
            }
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("%d\n", ans);

    return 0;
}