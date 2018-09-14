#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    cout << min({(N + M - K) / 3, N / 2, M});

    return 0;
}