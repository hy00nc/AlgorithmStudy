#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    long long N, M;
    cin >> N >> M;

    int two = 0;
    int five = 0;

    for (long long i = 2; i <= N; i *= 2) {
        two += N / i;
        two -= (N - M) / i;
        two -= M / i;
    }

    for (long long i = 5; i <= N; i *= 5) {
        five += N / i;
        five -= (N - M) / i;
        five -= M / i;
    }

    int ans = min(two, five);
    cout << ans << '\n';

    return 0;
}