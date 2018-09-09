#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);

    for (char x : str) {
        if ('A' <= x && x <= 'Z') {
            cout << (char)((x + 13 - 'A') % 26 + 'A');
        } else if ('a' <= x && x <= 'z') {
            cout << (char)((x + 13 - 'a') % 26 + 'a');
        } else {
            cout << x;
        }
    }
    cout << '\n';

    return 0;
}