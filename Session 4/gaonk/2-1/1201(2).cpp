#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    
    if (!(M + K - 1 <= N && N <= M * K)) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        v[i] = i + 1;
    }

    int st = 0;
    for (int i = 1; i <= M; i++) {
        int tmp = min(st + K, N - M + i);
        reverse(v.begin() + st, v.begin() + tmp);
        st = tmp;
    }

    for (int i = 0; i < N; i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';

    return 0;
}