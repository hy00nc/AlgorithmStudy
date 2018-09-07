#include <iostream>
#include <algorithm>
using namespace std;

int p[1001];
int arr[1001];

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> p[i];
    }

    for (int i = 1; i <= N; i++) {
        arr[i] = p[i];
        for (int j = 1; j < i; j++) {
            if (arr[i] < arr[i - j] + arr[j]) {
                arr[i] = arr[i - j] + arr[j];
            }
        }
    }
    cout << arr[N] << '\n';

    return 0;
}