#include <iostream>
using namespace std;

int arr[1000001];

int main() {
    int N;
    cin >> N;

    for (int i = 2; i <= N; i++) {
        int minNum = -1;
        if (i % 3 == 0) {
            if (minNum > arr[i / 3] + 1 || minNum == -1) {
                minNum = arr[i / 3] + 1;
            }
        }
        if (i % 2 == 0) {
            if (minNum > arr[i / 2] + 1 || minNum == -1) {
                minNum = arr[i / 2] + 1;
            } 
        }
        if (minNum == -1 || minNum > arr[i - 1] + 1) {
            minNum = arr[i - 1] + 1;
        }

        arr[i] = minNum;
    }

    cout << arr[N] << '\n';
    return 0;
}