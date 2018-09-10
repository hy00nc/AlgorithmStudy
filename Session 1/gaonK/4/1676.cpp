#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    int two = 0;
    int five = 0;

    for (int i = 2; i <= N; i *= 2) {
        two += N / i;
    }

    for (int i = 5; i <= N; i*= 5) {
        five += N / i;
    }

    int zeroCount = min(two, five);
    cout << zeroCount << '\n';

    return 0;
}