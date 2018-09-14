#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    vector<int> sumV(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    sumV[0] = v[0];
    for (int i = 1; i < N; i++) {
        sumV[i] = v[i] + sumV[i - 1];
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += sumV[i];
    }
    cout << ans << '\n';

    return 0;
}