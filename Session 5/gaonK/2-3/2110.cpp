#include <cstdio>
#include <algorithm>
using namespace std;

int a[200001];

int main() {
    int N, C;
    scanf("%d %d", &N, &C);

    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, a + N);

    int left = 1;
    int right = a[N - 1] - a[0];
    int ans = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        int prev = a[0];
        int cnt = 1;
        for (int i = 1; i < N; i++) {
            if (a[i] - prev >= mid) {
                cnt++;
                prev = a[i];
            } 
        }

        if (cnt >= C) {
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