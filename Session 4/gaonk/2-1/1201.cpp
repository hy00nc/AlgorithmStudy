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

    vector<int> group(M);
    group[0] = K;
    
    for (int i = 1; i < M; i++) {
        group[i] = (N - K) / (M - 1);
    }

    int remain = (M - 1 == 0) ? 0 : (N - K) % (M - 1);
    int idx = 1;
    while (remain > 0) {
        group[idx++]++;
        remain--;
    }

    int st = 0;
    for (int i = 0; i < M; i++) {
        reverse(v.begin() + st, v.begin() + st + group[i]);
        st += group[i];
    }

    for (int i = 0; i < N; i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}