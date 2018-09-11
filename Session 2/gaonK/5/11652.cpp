#include <iostream>
#include <algorithm>
using namespace std;

long long arr[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);
    long long prev = arr[0];
    int cnt = 1;
    int maxCnt = 1;
    long long ans = arr[0];
    for (int i = 1; i < N; i++) {
        if (prev == arr[i]) {
            cnt++;
            if (cnt > maxCnt) {
                maxCnt = cnt;
                ans = arr[i];
            }
        } else {
            prev = arr[i];
            cnt = 1;
        }
    }
    cout << ans << '\n';

    return 0;
}