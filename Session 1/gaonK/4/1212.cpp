#include <iostream>
#include <stack>
using namespace std;

int main() {
    string num;
    cin >> num;
    
    if (num == "0") {
        cout << 0 << '\n';
        return 0;
    }
    
    bool flag = false;
    for (char ch : num) {
        stack<int> s;
        int x = ch - '0';
        while (x > 0) {
            s.push(x % 2);
            x /= 2;
        }

        if (flag) {
            for (int i = 0; i < 3 - s.size(); i++) {
                cout << 0;
            }
        }

        while (!s.empty()) {
            cout << s.top();
            s.pop();
        }
        flag = true;
    }
    cout << '\n';

    return 0;
}