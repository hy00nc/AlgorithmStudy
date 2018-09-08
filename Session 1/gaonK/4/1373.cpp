#include <iostream>
#include <stack>
using namespace std;

int main() {
    string num;
    cin >> num;
    int idx = num.size() - 1;

    stack<int> s;
    while (idx >= 0) {
        int tmp = 0;
        int k = 0;
        for (int i = idx; i > idx - 3; i--) {
            if (i < 0) break;
            tmp += (num[i] - '0') * (1 << k);
            k++;
        }
        s.push(tmp);
        idx -= 3;
    }

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << '\n';

    return 0;
}