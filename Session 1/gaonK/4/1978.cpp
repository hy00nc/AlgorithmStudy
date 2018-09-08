#include <iostream>
using namespace std;

bool isPrime[1001];

int main() {
    
    for (int i = 2; i <= 1000; i++) {
        isPrime[i] = true;
    }

    for (int i = 2; i * i <= 1000; i++) {
        if (isPrime[i]) {
            for (int j = i + i; j <= 1000; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int N;
    cin >> N;
    int ans = 0;
    while (N--) {
        int x;
        cin >> x;

        if (isPrime[x]) {
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}