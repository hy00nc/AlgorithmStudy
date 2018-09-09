#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    stack<char> left, right;
    int size = str.size();
    for (char x : str) {
        left.push(x);
    }

    int N;
    cin >> N;
    while (N--) {
        char cmd;
        cin >> cmd;

        if (cmd == 'L') {
            if (!left.empty()) {
                char x = left.top();
                right.push(x);
                left.pop();
            }
        } else if (cmd == 'D') {
            if (!right.empty()) {
                char x = right.top();
                left.push(x);
                right.pop();
            }
        } else if (cmd == 'B') {
            if (!left.empty()) {
                left.pop();
            }
        } else if (cmd == 'P') {
            char x;
            cin >> x;
            left.push(x);
        }
    }

    int leftSize = left.size();
    for (int i = 0; i < leftSize; i++) {
        char x = left.top();
        right.push(x);
        left.pop();
    }

    int rightSize = right.size();
    for (int i = 0; i < rightSize; i++) {
        char x = right.top();
        cout << x;
        right.pop();
    }

    cout << '\n';
    
    return 0;
}