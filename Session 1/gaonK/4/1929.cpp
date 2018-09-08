#include <iostream>
using namespace std;

#define SIZE 1000000

bool isPrime[SIZE + 1];

int main() {
    
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

    int M, N;
    cin >> M >> N;

    for (int i = M; i <= N; i++) {
        if (isPrime[i]) {
            cout << i << '\n';
        }
    }

    return 0;
}