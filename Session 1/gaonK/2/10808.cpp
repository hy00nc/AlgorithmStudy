#include <iostream>
#include <string>
using namespace std;

int alphabet[26];

int main() {
    string str;
    cin >> str;

    for (char x : str) {
        alphabet[x - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        cout << alphabet[i] << ' ';
    }
    cout << '\n';

    return 0;
}