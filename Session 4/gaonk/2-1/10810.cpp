#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool cmp(char &a, char &b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    char num[100001];
    cin >> num;

    int size = strlen(num);
    int sum = 0;
    bool flag = false;
    for (int i = 0; i < size; i++) {
        sum += num[i] - '0';
        if (num[i] == '0') {
            flag = true;
        }
    }

    if (sum % 3 == 0 && flag) {
        sort(num, num + size, cmp);
        cout << num << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}