#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int ans = 1;
    for (int i = 2; i <= N; i++) {
        ans *= i;
    }
    cout << ans << '\n';

    return 0;
}