#include <iostream>
using namespace std;

int arr[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        arr[x]++;
    }
    
    for (int i = 1; i <= 10000; i++) {
        while (arr[i] > 0) {
            cout << i << '\n';
            arr[i]--;
        }
    }

    return 0;
}