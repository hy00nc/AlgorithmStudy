#include <iostream>
using namespace std;

#define SIZE 1000000

bool isPrime[SIZE + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i <= SIZE; i++) {
        isPrime[i] = true;
    }

    for (int i = 2; i * i <= SIZE; i++) {
        if (isPrime[i]) {
            for (int j = i + i; j <= SIZE; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int N;
    while (cin >> N && N != 0) {

        for (int i = 3; i < N; i++) {
            if (isPrime[i] && isPrime[N - i]) {
                cout << N << " = " << i << " + " << N - i << '\n';
                break;
            }
        }

    }

    return 0;
}