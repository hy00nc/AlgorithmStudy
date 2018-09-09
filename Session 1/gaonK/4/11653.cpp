#include <iostream>
using namespace std;

#define SIZE 10000000

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

    int N;
    cin >> N;

    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            while (N % i == 0) {
                cout << i << '\n';
                N /= i;
            }
        } 
        if (N == 1) break; 
    }

    return 0;
}