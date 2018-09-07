#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int leftDp[1001];
int rightDp[1001];

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (arr[j] < arr[i]) {
                leftDp[i] = max(leftDp[j] + 1, leftDp[i]);
            }
        }
    }

    for (int i = N; i >= 0; i--) {
        for (int j = N; j > i; j--) {
            if (arr[j] < arr[i]) {
                rightDp[i] = max(rightDp[j] + 1, rightDp[i]);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (ans < leftDp[i] + rightDp[i] + 1) {
            ans = leftDp[i] + rightDp[i] + 1;
        }
    }
    cout << ans << '\n';

    return 0;
}