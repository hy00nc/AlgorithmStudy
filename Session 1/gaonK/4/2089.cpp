#include <iostream>
using namespace std;

void solve(long long n) {
    if (n == 0) {
        return;
    }

    if (n % 2 == 0) {
        solve(-(n / 2));
        cout << 0;
    } else {
        if (n > 0) {
            solve(-(n / 2));
            cout << 1;
        } else {
            solve((-n + 1) / 2);
            cout << 1;
        }
    }

}

int main() {
    long long N;
    cin >> N;

    if (N == 0) {
        cout << 0 << '\n';
    } else {
        solve(N);
        cout << '\n';
    }
    
    return 0;
}