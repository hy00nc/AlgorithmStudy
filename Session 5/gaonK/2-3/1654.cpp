#include <cstdio>

long long a[10001];

int main() {
    int K, N;
    scanf("%d %d", &K, &N);

    long long maxLength;
    for (int i = 0; i < K; i++) {
        scanf("%lld", &a[i]);
        if (i == 0) {
            maxLength = a[i];
        } else {
            if (maxLength < a[i]) {
                maxLength = a[i];
            }
        }
    }

    long long left = 1;
    long long right = maxLength;
    long long mid;
    long long ans = 0;
    while (left <= right) {
        long long sum = 0;
        mid = (left + right) / 2;
        
        for (int i = 0; i < K; i++) {
            sum += a[i] / mid;
        }

        if (sum < N) {
            right = mid - 1;
        } else {
            if (ans < mid) {
                ans = mid;
            }
            left = mid + 1;
        }
    }

    printf("%lld\n", ans);

    return 0;
}